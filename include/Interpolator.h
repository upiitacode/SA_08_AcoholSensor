#ifndef _INTERPOLATOR_H
#define _INTERPOLATOR_H

#include <cmath>

struct Point2D{
	float x;
	float y;
};

class Interpolator{
	private:
		const float* x_data;
		const float* y_data;
		int data_size;
	public:
		Interpolator(const float* x_data, const float* y_data, int data_size);
		static float interpolate(float x1,float x2,float y1,float y2,float x);
		static float logloginterpolate(float x1,float x2,float y1,float y2,float x);
		static float logyinterpolate(float x1,float x2,float y1,float y2,float x);
		bool isGrowing(void);
		bool isXGrowing(void);
		int getPairIndex(float x);
		float gety(float x);
		float getyloglog(float x);
};

#endif// _INTERPOLATOR_H
