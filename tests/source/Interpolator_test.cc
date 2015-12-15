#include "gmock/gmock.h"
using ::testing::Eq;
using ::testing::FloatEq;

#include "Interpolator.h"

TEST(InterpolationTests, ThatInterpolationOfConstantIsConstant){
	float p1[] = {1.0,1.0};
	float p2[] = {2.0,1.0};
	float x = 1.5;
	float y = Interpolator::interpolate(p1[0],p2[0],p1[1],p2[1],x);
	EXPECT_THAT(y, FloatEq(1.0));
}

TEST(InterpolationTests, ThatInterpolationOfXIsX){
	float p1[] = {0.0,0.0};
	float p2[] = {1.0,1.0};
	float x = 1.5;
	float y = Interpolator::interpolate(p1[0],p2[0],p1[1],p2[1],x);
	EXPECT_THAT(y, FloatEq(1.5));
}

TEST(InterpolationTests, InterpolationWithUnitarySlopeAndOffset){
	float p1[] = {0.0,5.0};
	float p2[] = {1.0,6.0};
	float x = 1.5;
	float y = Interpolator::interpolate(p1[0],p2[0],p1[1],p2[1],x);
	EXPECT_THAT(y, FloatEq(6.5));
}

TEST(InterpolationTests, InterpolationWithNonUnitarySlopeAndOffset){
	float p1[] = {2.0,15.0};
	float p2[] = {4.0,20.0};
	float x = 5;
	float y = Interpolator::interpolate(p1[0],p2[0],p1[1],p2[1],x);
	EXPECT_THAT(y, FloatEq(22.5));
}

TEST(InterpolationTests, LogLogInterpolation){
	float x = 4;
	float y = Interpolator::logloginterpolate(2,8,10,1000,x);
	EXPECT_THAT(y, FloatEq(100));
}

TEST(InterpolationTests, WhenGrowingFunction){
	float x_data[] = {1,2};
	float y_data[] = {5,9};
	Interpolator interpolator(x_data,y_data,2);
	EXPECT_THAT(interpolator.isGrowing(), Eq(true));
}

TEST(InterpolationTests, WhenDataIsNotGrowing){
	float x_data[] = {1,2};
	float y_data[] = {9,5};
	Interpolator interpolator(x_data,y_data,2);
	EXPECT_THAT(interpolator.isGrowing(), Eq(false));
}

TEST(InterpolationTests, WhenXIsInsideXDataAndXGrowing){
	float x_data[] = {1,2,3,4};
	float y_data[] = {9,5,2,1};
	Interpolator interpolator(x_data,y_data,4);
	EXPECT_THAT(interpolator.getPairIndex(1.5), Eq(0));
	EXPECT_THAT(interpolator.getPairIndex(2.0), Eq(1));
	EXPECT_THAT(interpolator.getPairIndex(2.5), Eq(1));
	EXPECT_THAT(interpolator.getPairIndex(3.5), Eq(2));
}

TEST(InterpolationTests, WhenXIsInsideXDataAndXDrecreasing){
	float x_data[] = {4,3,2,1};
	float y_data[] = {9,5,2,1};
	Interpolator interpolator(x_data,y_data,4);
	EXPECT_THAT(interpolator.getPairIndex(1.5), Eq(2));
	EXPECT_THAT(interpolator.getPairIndex(2.5), Eq(1));
	EXPECT_THAT(interpolator.getPairIndex(3.0), Eq(1));
	EXPECT_THAT(interpolator.getPairIndex(3.5), Eq(0));
}

TEST(InterpolationTests, WhenXIsOutsideXDataAndXGrowing){
	float x_data[] = {1,2,3,4};
	float y_data[] = {9,5,2,1};
	Interpolator interpolator(x_data,y_data,4);
	EXPECT_THAT(interpolator.getPairIndex(0), Eq(0));
	EXPECT_THAT(interpolator.getPairIndex(5), Eq(2));
}

TEST(InterpolationTests, WhenXIsOutsideXDataAndXDrecreasing){
	float x_data[] = {4,3,2,1};
	float y_data[] = {9,5,2};
	Interpolator interpolator(x_data,y_data,4);
	EXPECT_THAT(interpolator.getPairIndex(0), Eq(2));
	EXPECT_THAT(interpolator.getPairIndex(5), Eq(0));
}

TEST(InterpolationTests, DataLinearInterpolation){
	float x_data[] = {1,2,3,4};
	float y_data[] = {1,3,6,10};
	Interpolator interpolator(x_data,y_data,4);
	EXPECT_THAT(interpolator.gety(0), FloatEq(-1));
	EXPECT_THAT(interpolator.gety(1), FloatEq(1));
	EXPECT_THAT(interpolator.gety(1.5), FloatEq(2));
	EXPECT_THAT(interpolator.gety(2.0), FloatEq(3));
	EXPECT_THAT(interpolator.gety(2.5), FloatEq(4.5));
	EXPECT_THAT(interpolator.gety(3.0), FloatEq(6));
	EXPECT_THAT(interpolator.gety(3.5), FloatEq(8));
	EXPECT_THAT(interpolator.gety(4), FloatEq(10));
	EXPECT_THAT(interpolator.gety(5), FloatEq(14));
}

TEST(InterpolationTests, DataLogLogInterpolation){
	float x_data[] = {2,8,16};
	float y_data[] = {30,3000,30000};
	Interpolator interpolator(x_data,y_data,3);
	EXPECT_THAT(interpolator.getyloglog(4), FloatEq(300));

	Interpolator interpolator2(y_data,x_data,3);
	EXPECT_THAT(interpolator2.getyloglog(300), FloatEq(4));
}

TEST(InterpolationTests, DataLogLogInterpolationDrecreasingY){
	float x_data[] = {2,8,16};
	float y_data[] = {3000,30,3};
	Interpolator interpolator(x_data,y_data,3);
	EXPECT_THAT(interpolator.getyloglog(4), FloatEq(300));

	Interpolator interpolator2(y_data,x_data,3);
	EXPECT_THAT(interpolator2.getyloglog(300), FloatEq(4));
}

