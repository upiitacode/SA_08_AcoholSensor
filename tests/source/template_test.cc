#include "gmock/gmock.h"
using ::testing::Eq;
using ::testing::FloatEq;

#include "Interpolator.h"

TEST(InterpolationTests, ThatInterpolationOfConstantIsConstant){
	Point2D p1 = {1.0,1.0};
	Point2D p2 = {2.0,1.0};
	Interpolator interpolator(p1,p2);
	EXPECT_THAT(interpolator.get_y(1.5), FloatEq(1.0));
}

TEST(InterpolationTests, ThatInterpolationOfXIsX){
	Point2D p1 = {0.0,0.0};
	Point2D p2 = {1.0,1.0};
	Interpolator interpolator(p1,p2);
	EXPECT_THAT(interpolator.get_y(1.5), FloatEq(1.5));
}

TEST(InterpolationTests, InterpolationWithUnitarySlopeAndOffset){
	Point2D p1 = {0.0,5.0};
	Point2D p2 = {1.0,6.0};
	Interpolator interpolator(p1,p2);
	EXPECT_THAT(interpolator.get_y(1.5), FloatEq(6.5));
}

TEST(InterpolationTests, InterpolationWithNonUnitarySlopeAndOffset){
	Point2D p1 = {2.0,15.0};
	Point2D p2 = {4.0,20.0};
	Interpolator interpolator(p1,p2);
	EXPECT_THAT(interpolator.get_y(5), FloatEq(22.5));
}

TEST(InterpolationTests, LogLogInterpolation){
	float x = 4;
	float y = Interpolator::logloginterpolate(2,8,10,1000,x);
	EXPECT_THAT(y, FloatEq(100));
}
