#include "gmock/gmock.h"
using ::testing::Eq;
using ::testing::FloatEq;

struct Point2D{
	float x;
	float y;
};

class LinearInterpolator{
	private:
		Point2D* point1;
		Point2D* point2;
	public:
		LinearInterpolator(Point2D& point1, Point2D& point2){
			this->point1 = &point1;
			this->point2 = &point2;
		}
		static float getYbyX(float x1,float x2,float y1,float y2,float x){
			float deltax = x2 - x1;
			float deltay = y2 - y1;
			float m = deltay/deltax;
			return (x-x1)*m + y1;
		}
		float get_y(float x){
			return getYbyX(point1->x,point2->x,point1->y,point2->y,x);
		}
};

TEST(InterpolationTests, ThatInterpolationOfConstantIsConstant){
	Point2D p1 = {1.0,1.0};
	Point2D p2 = {2.0,1.0};
	LinearInterpolator interpolator(p1,p2);
	EXPECT_THAT(interpolator.get_y(1.5), FloatEq(1.0));
}

TEST(InterpolationTests, ThatInterpolationOfXIsX){
	Point2D p1 = {0.0,0.0};
	Point2D p2 = {1.0,1.0};
	LinearInterpolator interpolator(p1,p2);
	EXPECT_THAT(interpolator.get_y(1.5), FloatEq(1.5));
}

TEST(InterpolationTests, InterpolationWithUnitarySlopeAndOffset){
	Point2D p1 = {0.0,5.0};
	Point2D p2 = {1.0,6.0};
	LinearInterpolator interpolator(p1,p2);
	EXPECT_THAT(interpolator.get_y(1.5), FloatEq(6.5));
}

TEST(InterpolationTests, InterpolationWithNonUnitarySlopeAndOffset){
	Point2D p1 = {2.0,15.0};
	Point2D p2 = {4.0,20.0};
	LinearInterpolator interpolator(p1,p2);
	EXPECT_THAT(interpolator.get_y(5), FloatEq(22.5));
}
