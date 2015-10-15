#include "gmock/gmock.h"
using ::testing::Eq;
using ::testing::StrEq;

TEST(TimerTest, TestThatStuff){
	ASSERT_THAT(1,Eq(1));
}
