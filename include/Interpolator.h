#ifndef _INTERPOLATOR_H
#define _INTERPOLATOR_H

#include <cmath>

struct Point2D{
	float x;
	float y;
};

class Interpolator{
	private:
		Point2D* point1;
		Point2D* point2;
	public:
		Interpolator(Point2D& point1, Point2D& point2);
		static float interpolate(float x1,float x2,float y1,float y2,float x);
		static float logloginterpolate(float x1,float x2,float y1,float y2,float x);
		static float logyinterpolate(float x1,float x2,float y1,float y2,float x);
		float get_y(float x);
};

#endif// _INTERPOLATOR_H
