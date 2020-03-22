#pragma once
ref class physics
{
public:
	static const float R = 8.314472;//General Gas constant
	static const float PI = 3.141592654;
	static const float Ro = 1.29; //Air density
	static const float nV = 0.000009f;//Air viscosity coefficient (20 degree)
	static const float AirVelocity = 343;//Air Velocity


	static float A;//Max Y
	static float WaveVelocity; //Wave Velocity
	static float f; //frequency
	static int TIMER;//for time updates when waved
	static float molecVelocity;//molecule velocity

	static int count;

	static bool WAVING;

	physics();
	static void setCount(int co);
	static void setWaveVelocity(float v);
	static void setf(float f);

	static float getF(float n, float m, float v, float L);
	static float getPressure(float n, float m, float v, float L);
	static float getW(float f);
	static float getK(float lmda);
	static float getLMDA(float v, float f);
	static float getDensity(int mass, float L);
	static float getIdealPressure(float n, float temp, float L);
	static float getWaveY(float x, float t);
	static float getRatio(float size);

	static float getReluctance(float mass, float L);
	static float getWaveEnergy(float mass, float L, float t);
	static float getP(float mass, float L);
	static float getI(float mass, float L);
	static float getVoicePressure(float mass, float L);
};