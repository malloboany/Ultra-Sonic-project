#include <cmath>
#include "physics .h"
physics::physics()
{
	A = 1.0f;
	count = 0;
	WaveVelocity = 1;
	f = 1;
}

float physics::getF(float n, float m, float v, float L){
	return ((1 / 3)*n*m*v*v) / L;
}

float physics::getPressure(float n, float m, float v, float L){
	return ( n * m * v * v / 3)/(L * L * L);
}
float physics::getW(float f){
	return 2 * PI*f;
}
float physics::getK(float lmda){
	return 2 * PI / lmda;
}
float physics::getLMDA(float velocity, float f){
	return velocity / f;
}
float physics::getDensity(int mass, float L){
	return mass / (L*L*L);
}
float physics::getIdealPressure(float n, float temp, float L){
	return n * physics::R * temp / (L*L*L);
}

float physics::getWaveY(float x, float t){
	return A*sinf(physics::getK(physics::getLMDA(WaveVelocity, f))*x - physics::getW(f)*t);
}

void physics::setCount(int co){
	count = co;
}
float physics::getRatio(float size){
	return getDensity(physics::count, size) / Ro;
}
void physics::setWaveVelocity(float v){
	physics::WaveVelocity = v;
}
void physics::setf(float f){
	physics::f = f;
}

float physics::getReluctance(float mass, float L){

	return getDensity(mass, L)*WaveVelocity;
}
float physics::getWaveEnergy(float mass, float L, float t){
	if (WAVING)
	return 2 * PI * PI * getDensity(mass, L) * 2 * A * L * WaveVelocity * t * f * f * A *A;
	else return 0;
}

float physics::getP(float mass, float L){
	if (WAVING)
	return 2 * PI * PI * getDensity(mass, L) * 2 * A * L * WaveVelocity * f * f * A *A;
	else return 0;
}

float physics::getI(float mass, float L){
	if (WAVING)
	return 2 * PI * PI * getDensity(mass, L) * WaveVelocity * f * f * A *A;
	else return 0;
}

float physics::getVoicePressure(float mass,float L){
	if (WAVING)
		return 2 * PI * getDensity(mass, L) * AirVelocity * A * f;
	else
		return 0;
}