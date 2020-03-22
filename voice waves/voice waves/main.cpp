

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <stdlib.h>
#include <vector>
#include "MyForm.h"


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "MyForm.h"
#include "vec3f.h"
#include "physics .h"

using namespace std;
using namespace voicewaves;

bool SKEY[255];
bool waved;

void SpecialKeys(int key, int x, int y){
	SKEY[key] = true;
}
void SpecialKeysUp(int key, int x, int y){
	SKEY[key] = false;
}
//Returns a random float from 0 to < 1
float randomFloat() {
	return (float)rand() / ((float)RAND_MAX + 1);
}
float GRAVITY = 10.0f;
float getGravity(){
	return GRAVITY;
}
void setGRAVITY(float grav){
	GRAVITY = grav;
}
float BOX_SIZE = 10.0f; //The length of one side of the box
void setSize(float size){
	//_balls.clear();
	BOX_SIZE = size;
}
//The amount of time between each time that we handle collisions and apply the
//effects of gravity
const float TIME_BETWEEN_UPDATES = 0.01f;
const int TIMER_MS = 25; //The number of milliseconds to which the timer is set

//Stores information regarding a ball
struct Ball {
	Vec3f v; //Velocity
	Vec3f pos; //Position
	float r; //Radius
	Vec3f color;
};

enum Wall { WALL_LEFT, WALL_RIGHT, WALL_FAR, WALL_NEAR, WALL_TOP, WALL_BOTTOM };

//Stores a pair of balls
struct BallPair {
	Ball* ball1;
	Ball* ball2;
};

//Stores a ball and a wall
struct BallWallPair {
	Ball* ball;
	Wall wall;
};

const int MAX_OCTREE_DEPTH = 6;
const int MIN_BALLS_PER_OCTREE = 3;
const int MAX_BALLS_PER_OCTREE = 6;

//Our data structure for making collision detection faster
class Octree {
private:
	Vec3f corner1; //(minX, minY, minZ)
	Vec3f corner2; //(maxX, maxY, maxZ)
	Vec3f center;//((minX + maxX) / 2, (minY + maxY) / 2, (minZ + maxZ) / 2)

	/* The children of this, if this has any.  children[0][*][*] are the
	* children with x coordinates ranging from minX to centerX.
	* children[1][*][*] are the children with x coordinates ranging from
	* centerX to maxX.  Similarly for the other two dimensions of the
	* children array.
	*/
	Octree *children[2][2][2];
	//Whether this has children
	bool hasChildren;
	//The balls in this, if this doesn't have any children
	set<Ball*> balls;
	//The depth of this in the tree
	int depth;
	//The number of balls in this, including those stored in its children
	int numBalls;

	//Adds a ball to or removes one from the children of this
	void fileBall(Ball* ball, Vec3f pos, bool addBall) {
		//Figure out in which child(ren) the ball belongs
		for (int x = 0; x < 2; x++) {
			if (x == 0) {
				if (pos[0] - ball->r > center[0]) {
					continue;
				}
			}
			else if (pos[0] + ball->r < center[0]) {
				continue;
			}

			for (int y = 0; y < 2; y++) {
				if (y == 0) {
					if (pos[1] - ball->r > center[1]) {
						continue;
					}
				}
				else if (pos[1] + ball->r < center[1]) {
					continue;
				}

				for (int z = 0; z < 2; z++) {
					if (z == 0) {
						if (pos[2] - ball->r > center[2]) {
							continue;
						}
					}
					else if (pos[2] + ball->r < center[2]) {
						continue;
					}

					//Add or remove the ball
					if (addBall) {
						children[x][y][z]->add(ball);
					}
					else {
						children[x][y][z]->remove(ball, pos);
					}
				}
			}
		}
	}

	//Creates children of this, and moves the balls in this to the children
	void haveChildren() {
		for (int x = 0; x < 2; x++) {
			float minX;
			float maxX;
			if (x == 0) {
				minX = corner1[0];
				maxX = center[0];
			}
			else {
				minX = center[0];
				maxX = corner2[0];
			}

			for (int y = 0; y < 2; y++) {
				float minY;
				float maxY;
				if (y == 0) {
					minY = corner1[1];
					maxY = center[1];
				}
				else {
					minY = center[1];
					maxY = corner2[1];
				}

				for (int z = 0; z < 2; z++) {
					float minZ;
					float maxZ;
					if (z == 0) {
						minZ = corner1[2];
						maxZ = center[2];
					}
					else {
						minZ = center[2];
						maxZ = corner2[2];
					}

					children[x][y][z] = new Octree(Vec3f(minX, minY, minZ),
						Vec3f(maxX, maxY, maxZ),
						depth + 1);
				}
			}
		}

		//Remove all balls from "balls" and add them to the new children
		for (set<Ball*>::iterator it = balls.begin(); it != balls.end();
			it++) {
			Ball* ball = *it;
			fileBall(ball, ball->pos, true);
		}
		balls.clear();

		hasChildren = true;
	}

	//Adds all balls in this or one of its descendants to the specified set
	void collectBalls(set<Ball*> &bs) {
		if (hasChildren) {
			for (int x = 0; x < 2; x++) {
				for (int y = 0; y < 2; y++) {
					for (int z = 0; z < 2; z++) {
						children[x][y][z]->collectBalls(bs);
					}
				}
			}
		}
		else {
			for (set<Ball*>::iterator it = balls.begin(); it != balls.end();
				it++) {
				Ball* ball = *it;
				bs.insert(ball);
			}
		}
	}

	//Destroys the children of this, and moves all balls in its descendants
	//to the "balls" set
	void destroyChildren() {
		//Move all balls in descendants of this to the "balls" set
		collectBalls(balls);

		for (int x = 0; x < 2; x++) {
			for (int y = 0; y < 2; y++) {
				for (int z = 0; z < 2; z++) {
					delete children[x][y][z];
				}
			}
		}

		hasChildren = false;
	}

	//Removes the specified ball at the indicated position
	void remove(Ball* ball, Vec3f pos) {
		numBalls--;

		if (hasChildren && numBalls < MIN_BALLS_PER_OCTREE) {
			destroyChildren();
		}

		if (hasChildren) {
			fileBall(ball, pos, false);
		}
		else {
			balls.erase(ball);
		}
	}

	/* Helper fuction for potentialBallWallCollisions(vector).  Adds
	* potential ball-wall collisions to cs, where w is the type of wall,
	* coord is the relevant coordinate of the wall ('x', 'y', or 'z'), and
	* dir is 0 if the wall is in the negative direction and 1 if it is in
	* the positive direction.  Assumes that this is in the extreme
	* direction of the coordinate, e.g. if w is WALL_TOP, the function
	* assumes that this is in the far upward direction.
	*/
	void potentialBallWallCollisions(vector<BallWallPair> &cs,
		Wall w, char coord, int dir) {
		if (hasChildren) {
			//Recursively call potentialBallWallCollisions on the correct
			//half of the children (e.g. if w is WALL_TOP, call it on
			//children above centerY)
			for (int dir2 = 0; dir2 < 2; dir2++) {
				for (int dir3 = 0; dir3 < 2; dir3++) {
					Octree *child = NULL;
					switch (coord) {
					case 'x':
						child = children[dir][dir2][dir3];
						break;
					case 'y':
						child = children[dir2][dir][dir3];
						break;
					case 'z':
						child = children[dir2][dir3][dir];
						break;
					}
					child->potentialBallWallCollisions(cs, w, coord, dir);
				}
			}
		}
		else {
			//Add (ball, w) for all balls in this
			for (set<Ball*>::iterator it = balls.begin(); it != balls.end();
				it++) {
				Ball* ball = *it;
				BallWallPair bwp;
				bwp.ball = ball;
				bwp.wall = w;
				cs.push_back(bwp);
			}
		}
	}
public:
	//Constructs a new Octree.  c1 is (minX, minY, minZ), c2 is (maxX, maxY,
	//maxZ), and d is the depth, which starts at 1.
	Octree(Vec3f c1, Vec3f c2, int d) {
		corner1 = c1;
		corner2 = c2;
		center = (c1 + c2) / 2;
		depth = d;
		numBalls = 0;
		hasChildren = false;
	}

	//Destructor
	~Octree() {
		if (hasChildren) {
			destroyChildren();
		}
	}

	//Adds a ball to this
	void add(Ball* ball) {
		numBalls++;
		if (!hasChildren && depth < MAX_OCTREE_DEPTH &&
			numBalls > MAX_BALLS_PER_OCTREE) {
			haveChildren();
		}

		if (hasChildren) {
			fileBall(ball, ball->pos, true);
		}
		else {
			balls.insert(ball);
		}
	}

	//Removes a ball from this
	void remove(Ball* ball) {
		remove(ball, ball->pos);
	}

	//Changes the position of a ball in this from oldPos to ball->pos
	void ballMoved(Ball* ball, Vec3f oldPos) {
		remove(ball, oldPos);
		add(ball);
	}

	//Adds potential ball-ball collisions to the specified set
	void potentialBallBallCollisions(vector<BallPair> &collisions) {
		if (hasChildren) {
			for (int x = 0; x < 2; x++) {
				for (int y = 0; y < 2; y++) {
					for (int z = 0; z < 2; z++) {
						children[x][y][z]->
							potentialBallBallCollisions(collisions);
					}
				}
			}
		}
		else {
			//Add all pairs (ball1, ball2) from balls
			for (set<Ball*>::iterator it = balls.begin(); it != balls.end();
				it++) {
				Ball* ball1 = *it;
				for (set<Ball*>::iterator it2 = balls.begin();
					it2 != balls.end(); it2++) {
					Ball* ball2 = *it2;
					//This test makes sure that we only add each pair once
					if (ball1 < ball2) {
						BallPair bp;
						bp.ball1 = ball1;
						bp.ball2 = ball2;
						collisions.push_back(bp);
					}
				}
			}
		}
	}

	//Adds potential ball-wall collisions to the specified set
	void potentialBallWallCollisions(vector<BallWallPair> &collisions) {
		potentialBallWallCollisions(collisions, WALL_LEFT, 'x', 0);
		potentialBallWallCollisions(collisions, WALL_RIGHT, 'x', 1);
		potentialBallWallCollisions(collisions, WALL_BOTTOM, 'y', 0);
		potentialBallWallCollisions(collisions, WALL_TOP, 'y', 1);
		potentialBallWallCollisions(collisions, WALL_FAR, 'z', 0);
		potentialBallWallCollisions(collisions, WALL_NEAR, 'z', 1);
	}
};

//Puts potential ball-ball collisions in potentialCollisions.  It must return
//all actual collisions, but it need not return only actual collisions.
void potentialBallBallCollisions(vector<BallPair> &potentialCollisions,
	vector<Ball*> &balls, Octree* octree) {
	//Fast method
	octree->potentialBallBallCollisions(potentialCollisions);

	/*
	//Slow method
	for(unsigned int i = 0; i < balls.size(); i++) {
	for(unsigned int j = i + 1; j < balls.size(); j++) {
	BallPair bp;
	bp.ball1 = balls[i];
	bp.ball2 = balls[j];
	potentialCollisions.push_back(bp);
	}
	}
	*/
}

//Puts potential ball-wall collisions in potentialCollisions.  It must return
//all actual collisions, but it need not return only actual collisions.
void potentialBallWallCollisions(vector<BallWallPair> &potentialCollisions,
	vector<Ball*> &balls, Octree* octree) {
	//Fast method
	octree->potentialBallWallCollisions(potentialCollisions);

	/*
	//Slow method
	Wall walls[] =
	{WALL_LEFT, WALL_RIGHT, WALL_FAR, WALL_NEAR, WALL_TOP, WALL_BOTTOM};
	for(unsigned int i = 0; i < balls.size(); i++) {
	for(int j = 0; j < 6; j++) {
	BallWallPair bwp;
	bwp.ball = balls[i];
	bwp.wall = walls[j];
	potentialCollisions.push_back(bwp);
	}
	}
	*/
}

//Moves all of the balls by their velocity times dt
void moveBalls(vector<Ball*> &balls, Octree* octree, float dt) {
	for (unsigned int i = 0; i < balls.size(); i++) {
		Ball* ball = balls[i];
		Vec3f oldPos = ball->pos;
		ball->pos += ball->v * dt;
		octree->ballMoved(ball, oldPos);
	}
}

//Decreases the y coordinate of the velocity of each ball by GRAVITY *
//TIME_BETWEEN_UPDATES
void applyGravity(vector<Ball*> &balls) {
	MyForm ^ g = gcnew MyForm();
	setGRAVITY(g->GRAV);
	for (unsigned int i = 0; i < balls.size(); i++) {
		Ball* ball = balls[i];
		ball->v -= Vec3f(0, GRAVITY * TIME_BETWEEN_UPDATES, 0);
	}
}

//Returns whether two balls are colliding
bool testBallBallCollision(Ball* b1, Ball* b2) {
	//Check whether the balls are close enough
	float r = b1->r + b2->r;
	if ((b1->pos - b2->pos).magnitudeSquared() < r * r) {
		//Check whether the balls are moving toward each other
		Vec3f netVelocity = b1->v - b2->v;
		Vec3f displacement = b1->pos - b2->pos;
		return netVelocity.dot(displacement) < 0;
	}
	else
		return false;
}

//Handles all ball-ball collisions
void handleBallBallCollisions(vector<Ball*> &balls, Octree* octree) {
	vector<BallPair> bps;
	potentialBallBallCollisions(bps, balls, octree);
	for (unsigned int i = 0; i < bps.size(); i++) {
		BallPair bp = bps[i];

		Ball* b1 = bp.ball1;
		Ball* b2 = bp.ball2;
		if (testBallBallCollision(b1, b2)) {
			//Make the balls reflect off of each other
			Vec3f displacement = (b1->pos - b2->pos).normalize();
			b1->v -= 2 * displacement * b1->v.dot(displacement);
			b2->v -= 2 * displacement * b2->v.dot(displacement);
		}
	}
}

//Returns the direction from the origin to the wall
Vec3f wallDirection(Wall wall) {
	switch (wall) {
	case WALL_LEFT:
		return Vec3f(-1, 0, 0);
	case WALL_RIGHT:
		return Vec3f(1, 0, 0);
	case WALL_FAR:
		return Vec3f(0, 0, -1);
	case WALL_NEAR:
		return Vec3f(0, 0, 1);
	case WALL_TOP:
		return Vec3f(0, 1, 0);
	case WALL_BOTTOM:
		return Vec3f(0, -1, 0);
	default:
		return Vec3f(0, 0, 0);
	}
}

//Returns whether a ball and a wall are colliding
bool testBallWallCollision(Ball* ball, Wall wall) {
	Vec3f dir = wallDirection(wall);
	//Check whether the ball is far enough in the "dir" direction, and whether
	//it is moving toward the wall
	return ball->pos.dot(dir) + ball->r > BOX_SIZE / 2 &&
		ball->v.dot(dir) > 0;
}

//Handles all ball-wall collisions
void handleBallWallCollisions(vector<Ball*> &balls, Octree* octree) {
	vector<BallWallPair> bwps;
	potentialBallWallCollisions(bwps, balls, octree);
	for (unsigned int i = 0; i < bwps.size(); i++) {
		BallWallPair bwp = bwps[i];

		Ball* b = bwp.ball;
		Wall w = bwp.wall;
		if (testBallWallCollision(b, w)) {
			//Make the ball reflect off of the wall
			Vec3f dir = (wallDirection(w)).normalize();
			b->v -= 2 * dir * b->v.dot(dir);
		}
	}
}

//Applies gravity and handles all collisions.  Should be called every
//TIME_BETWEEN_UPDATES seconds.
void performUpdate(vector<Ball*> &balls, Octree* octree) {
	applyGravity(balls);
	handleBallBallCollisions(balls, octree);
	handleBallWallCollisions(balls, octree);
}

//Advances the state of the balls by t.  timeUntilUpdate is the amount of time
//until the next call to performUpdate.
void advance(vector<Ball*> &balls,
	Octree* octree,
	float t,
	float &timeUntilUpdate) {
	while (t > 0) {
		if (timeUntilUpdate <= t) {
			moveBalls(balls, octree, timeUntilUpdate);
			performUpdate(balls, octree);
			t -= timeUntilUpdate;
			timeUntilUpdate = TIME_BETWEEN_UPDATES;
		}
		else {
			moveBalls(balls, octree, t);
			timeUntilUpdate -= t;
			t = 0;
		}
	}
}





vector<Ball*> _balls; //All of the balls in play
float _angle = 0.0f; //The camera angle
Octree* _octree; //An octree with all af the balls
//The amount of time until performUpdate should be called
float _timeUntilUpdate = 0;
GLuint _textureId;

//Deletes everything.  This should be called when exiting the program.
void cleanup() {
	for (unsigned int i = 0; i < _balls.size(); i++) {
		delete _balls[i];
	}
	delete _octree;
}
void shape(){
	glBegin(GL_QUADS);
	glVertex3f(BOX_SIZE / 2, 0, 0);
	glVertex3f(BOX_SIZE / 2 + 1, 2, 0);
	glVertex3f(BOX_SIZE / 2 + 3, 0, 0);
	glEnd();

}
void wave(){
	for (int i = 0; i < _balls.size(); i++){
		if (_balls[i]->pos[1] < physics::A && _balls[i]->pos[1] >= 0)
			_balls[i]->v = Vec3f(physics::WaveVelocity, physics::WaveVelocity, _balls[i]->v[2]);
		if (_balls[i]->pos[1] > -physics::A && _balls[i]->pos[1] < 0)
			_balls[i]->v = Vec3f( physics::WaveVelocity,-physics::WaveVelocity, _balls[i]->v[2]);
	}
}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		cleanup();
		exit(0);
	case 'w':
		if (!waved){
			if (physics::A != 0){
				waved = true;
				physics::WAVING = true;
				wave();
			}
		}
		else {
			waved = false;
			physics::WAVING = false;
		}
		break;
	case ' ':
		//Add 20 balls with a random position, velocity, radius, and color
		for (int i = 0; i < 20; i++) {
			Ball* ball = new Ball();
			ball->pos = Vec3f((BOX_SIZE)* randomFloat() - (BOX_SIZE / 2),
				(BOX_SIZE)* randomFloat() - (BOX_SIZE / 2),
				(BOX_SIZE)* randomFloat() - (BOX_SIZE / 2));
			ball->v = Vec3f(8 * randomFloat() - 4,
				8 * randomFloat() - 4,
				8 * randomFloat() - 4);
			ball->r = 0.1f * randomFloat() + 0.1f;
			ball->color = Vec3f(0.6f * randomFloat() + 0.2f,
				0.6f * randomFloat() + 0.2f,
				0.6f * randomFloat() + 0.2f);
			_balls.push_back(ball);
			_octree->add(ball);
		}
		physics::count = _balls.size();
		break;
	/*case 'r':
		MyForm ^ jj = gcnew MyForm();
		cout << physics::getPressure(1,1,1,1) << endl;
		break;*/
	}
}

/*GLuint loadTexture(Image* image) {
GLuint textureId;
glGenTextures(1, &textureId);
glBindTexture(GL_TEXTURE_2D, textureId);
glTexImage2D(GL_TEXTURE_2D,
0,
GL_RGB,
image->width, image->height,
0,
GL_RGB,
GL_UNSIGNED_BYTE,
image->pixels);
return textureId;
}*/

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);


	//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	//glEnable(GL_BLEND); 
	//glDisable(GL_DEPTH_TEST);
	/*Image *image = loadBMP("vtr.bmp");
	_textureId = loadTexture(image);
	delete image;*/
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}
void drawWaves(){
	int rat = 1000;
	float y;
	/*glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2 - 6, 0, 0);
	glVertex3f(BOX_SIZE / 2, 0, BOX_SIZE / 2);
	glEnd();*/
	glBegin(GL_POINTS);
	for (int i = 0; i < rat; i++){
		glColor3f(1.0f, 0.0f, 0.0f);
		y = physics::getWaveY((-BOX_SIZE / 2 - 5) + i*(2 * BOX_SIZE / 2 + 5) / rat, i);
		//cout << y << endl;
		glVertex3f((-BOX_SIZE / 2 - 5) + i*(2 * BOX_SIZE / 2 + 5) / rat, y,
			(((-BOX_SIZE / 2 - 5) + i*(2 * BOX_SIZE / 2 + 5) / rat) - (-BOX_SIZE / 2 - 5))*(BOX_SIZE / 2) / (2 * BOX_SIZE / 2 + 5));
	}
	glEnd();

	/*glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2 - 6, 0, 0);
	glVertex3f(BOX_SIZE / 2, 0, -BOX_SIZE / 2);
	glEnd();*/
	glBegin(GL_POINTS);
	for (int i = 0; i < rat; i++){
		glColor3f(1.0f, 0.0f, 0.0f);
		y = physics::getWaveY((-BOX_SIZE / 2 - 5) + i*(2 * BOX_SIZE / 2 + 5) / rat, i);
		//cout << y << endl;
		glVertex3f((-BOX_SIZE / 2 - 5) + i*(2 * BOX_SIZE / 2 + 5) / rat, y,
			(((-BOX_SIZE / 2 - 5) + i*(2 * BOX_SIZE / 2 + 5) / rat) - (-BOX_SIZE / 2 - 5))*(-BOX_SIZE / 2) / (2 * BOX_SIZE / 2 + 5));
	}
	glEnd();

}
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -20.0f);
	glRotatef(-_angle, 0.0f, 1.0f, 0.0f);

	GLfloat ambientColor[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	GLfloat lightColor[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat lightPos[] = { 1.0f, 0.2f, 0.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	glEnable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	//wave yellow zone
	glBegin(GL_QUADS);
	//glColor3f(1, 0, 1);
	glColor4f(1, 1, 0, 0.2);
	glColorMask(1, 0, 0, 0);

	//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	//
	///glDisable(GL_DEPTH_TEST);

	glVertex3f(BOX_SIZE / 2, physics::A, BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -physics::A, BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, -physics::A, BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, physics::A, BOX_SIZE / 2);
	glEnd();

	glBegin(GL_QUADS);
	glColor4f(1, 1, 0, 0.2);
	glColorMask(1, 0, 0, 0);
	glVertex3f(BOX_SIZE / 2, physics::A, -BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -physics::A, -BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, -physics::A, -BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, physics::A, -BOX_SIZE / 2);
	glEnd();

	glBegin(GL_QUADS);
	glColor4f(1, 1, 0, 0.2);
	glColorMask(1, 0, 0, 0);
	glVertex3f(BOX_SIZE / 2, physics::A, BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -physics::A, BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -physics::A, -BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, physics::A, -BOX_SIZE / 2);
	glEnd();

	glBegin(GL_QUADS);
	glColor4f(1, 1, 0, 0.2);
	glColorMask(1, 0, 0, 0);
	glVertex3f(-BOX_SIZE / 2, physics::A, BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, -physics::A, BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, -physics::A, -BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, physics::A, -BOX_SIZE / 2);
	glEnd();


	//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	//Border of cube
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glEnd();
	////////////////
	//Generator
	glBegin(GL_TRIANGLES);
	glVertex3f(-BOX_SIZE / 2 - 5, 1, 1);
	glVertex3f(-BOX_SIZE / 2 - 5, 1, -1);
	glVertex3f(-BOX_SIZE / 2 - 7, 0, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-BOX_SIZE / 2 - 5, 1, 1);
	glVertex3f(-BOX_SIZE / 2 - 7, 0, 0);
	glVertex3f(-BOX_SIZE / 2 - 5, -1, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-BOX_SIZE / 2 - 5, 1, -1);
	glVertex3f(-BOX_SIZE / 2 - 7, 0, 0);
	glVertex3f(-BOX_SIZE / 2 - 5, -1, 0);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2 - 7, 0, 0);
	glVertex3f(-BOX_SIZE / 2 - 5, 1, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-BOX_SIZE / 2 - 7, 0, 0);
	glVertex3f(-BOX_SIZE / 2 - 5, 1, 1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-BOX_SIZE / 2 - 7, 0, 0);
	glVertex3f(-BOX_SIZE / 2 - 5, -1, 0);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-BOX_SIZE / 2 - 5, 1, 1);
	glVertex3f(-BOX_SIZE / 2 - 5, -1, 0);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-BOX_SIZE / 2 - 5, -1, 0);
	glVertex3f(-BOX_SIZE / 2 - 5, 1, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-BOX_SIZE / 2 - 5, 1, 1);
	glVertex3f(-BOX_SIZE / 2 - 5, 1, -1);
	glEnd();

	//Draw the top and the bottom of the box
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	//bottom
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	//top
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);

	glEnd();

	//Draw the waves
	if (waved && physics::A!=0)
		drawWaves();

	//Draw the balls
	for (unsigned int i = 0; i < _balls.size(); i++) {
		Ball* ball = _balls[i];
		glPushMatrix();
		glTranslatef(ball->pos[0], ball->pos[1], ball->pos[2]);
		glColor3f(ball->color[0], ball->color[1], ball->color[2]);
		glutSolidSphere(ball->r, 12, 12); //Draw a sphere
		glPopMatrix();
	}
	applyGravity(_balls);

	glutSwapBuffers();
}

//Called every TIMER_MS milliseconds
void update(int value) {
	MyForm ^ g = gcnew MyForm();
	if (BOX_SIZE != g->SIZE)
		_balls.clear();
	physics::count = _balls.size();

	setSize(g->SIZE);
	float count = 0;
	for (int i = 0; i<_balls.size(); i++){
		count += _balls[i]->v.magnitude();
	}
	physics::molecVelocity = count / _balls.size();

	advance(_balls, _octree, (float)TIMER_MS / 1000.0f, _timeUntilUpdate);
	_angle += (float)TIMER_MS / 100;
	if (_angle > 360) {
		_angle -= 360;
	}
	if (physics::A == 0){
		waved = false;
		physics::WAVING = false;
	}
	if (waved){
		wave();
		physics::TIMER += 25;
	}
	else physics::TIMER = 0;

	applyGravity(_balls);

	glutPostRedisplay();
	glutTimerFunc(TIMER_MS, update, 0);
}

void action(){
	/*if (SKEY['w'])
		exit(0);
	drawScene();	*/
}
int main(int argc, char** argv) {
	srand((unsigned int)time(0)); //Seed the random number generator

	physics::A = 1;
	physics::f = 1;
	physics::WaveVelocity = 1;
	physics::TIMER = 0;
	physics::molecVelocity = 0;
	physics::WAVING = false;

	waved = false;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 600);

	glutCreateWindow("___Ultrasonic Project___");
	initRendering();
	//glutFullScreen();

	MyForm ^ g = gcnew MyForm();
	g->Show();
	setSize(g->SIZE);
	//setGravity(g->GET_GRAVITY());

	_octree = new Octree(Vec3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2),
		Vec3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2), 1);

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutIdleFunc(action);
	glutSpecialFunc(SpecialKeys);
	glutSpecialUpFunc(SpecialKeysUp);


	glutTimerFunc(TIMER_MS, update, 0);

	glutMainLoop();

	return 0;
};