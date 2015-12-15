#include "Interpolator.h"

Interpolator::Interpolator(Point2D& point1, Point2D& point2){
	this->point1 = &point1;
	this->point2 = &point2;
}

float Interpolator::interpolate(float x1,float x2,float y1,float y2,float x){
	float deltax = x2 - x1;
	float deltay = y2 - y1;
	float m = deltay/deltax;
	return (x-x1)*m + y1;
}

float Interpolator::logloginterpolate(float x1,float x2,float y1,float y2,float x){
	return pow(10,interpolate(log10(x1),log10(x2),log10(y1),log10(y2),log10(x)));
}

float Interpolator::logyinterpolate(float x1,float x2,float y1,float y2,float x){
	return pow(10,interpolate(x1,x2,log10(y1),log10(y2),x));
}

float Interpolator::get_y(float x){
	return interpolate(point1->x,point2->x,point1->y,point2->y,x);
}
