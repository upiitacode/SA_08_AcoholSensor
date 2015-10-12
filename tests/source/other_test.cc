#include "gmock/gmock.h"
using ::testing::Eq;

TEST(OtherTest,ThatOtherTestWorks){
	ASSERT_THAT(9,Eq(9));
}
TEST(OtherTest,ThatWeHaveTwoTests){
	ASSERT_THAT(9,Eq(9));
}
