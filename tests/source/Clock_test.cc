#include "gmock/gmock.h"
#include "Clock.h"
using ::testing::Eq;
using ::testing::Ne;
using ::testing::StrEq;

TEST(ClockTest, ThatTimeIsZeroAtStart){
	Clock clockUT;
	int initialTime = clockUT.getTimeAsInt();
	ASSERT_THAT(initialTime,Eq(0));
}

TEST(ClockTest, ThatTickIncreasesTimeByOne){
	Clock clockUT;
	clockUT.tick();
	ASSERT_THAT(clockUT.getTimeAsInt(),Eq(1));
}

TEST(ClockTest, That1000MilliesecondsEqOneSecond){
	Clock clockUT1;
	Clock clockUT2;

	Time time1(0,0,0,1000);
	Time time2(0,0,1,0);

	clockUT1.setTime(time1);
	clockUT2.setTime(time2);

	ASSERT_THAT(clockUT1.getTimeAsInt(),Eq(clockUT2.getTimeAsInt()));
}

TEST(ClockTest, That60SecondsEqOneMinute){
	Clock clockUT1;
	Clock clockUT2;

	Time time1(0,0,60,0);
	Time time2(0,1,0,0);

	clockUT1.setTime(time1);
	clockUT2.setTime(time2);

	ASSERT_THAT(clockUT1.getTimeAsInt(),Eq(clockUT2.getTimeAsInt()));
}

TEST(ClockTest, That60MinutesEq1Hour){
	Clock clockUT1;
	Clock clockUT2;

	Time time1(0,60,0,0);
	Time time2(1,0,0,0);

	clockUT1.setTime(time1);
	clockUT2.setTime(time2);

	ASSERT_THAT(clockUT1.getTimeAsInt(),Eq(clockUT2.getTimeAsInt()));
}

TEST(ClockTest, ThatTimerOverflowsAt23_59_59_999WhenTicking){
	Clock clockUT1;
	Time time1(23,59,59,999);

	clockUT1.setTime(time1);

	ASSERT_THAT(clockUT1.getTimeAsInt(),Ne(0));
	clockUT1.tick();
	ASSERT_THAT(clockUT1.getTimeAsInt(),Eq(0));
}

TEST(ClockTest, ThatTimerOverflowsAt23_59_59_999WhenSettingTime){
	Clock clockUT1;
	Time time1(23,59,59,999);
	clockUT1.setTime(time1);
	ASSERT_THAT(clockUT1.getTimeAsInt(),Ne(0));

	Time time2(24,0,0,0);
	clockUT1.setTime(time2);
	ASSERT_THAT(clockUT1.getTimeAsInt(),Eq(0));
}

TEST(ClockTest, ThatTimeCanBeSetUsingATimeObject){
	Clock clockUT;
	Time time(0,0,0,20);
	clockUT.setTime(time);
	ASSERT_THAT(clockUT.getTimeAsInt(),Eq(20));
}

TEST(ClockTest, ThatTimeCanBeSavedUsingATimeObject){
	Clock clockUT;

	Time originalTime(23,59,59,999);
	clockUT.setTime(originalTime);

	Time savedTime(0,0,0,0);
	clockUT.getTime(savedTime);

	ASSERT_THAT(savedTime.milliseconds, Eq(originalTime.milliseconds));
	ASSERT_THAT(savedTime.seconds, Eq(originalTime.seconds));
	ASSERT_THAT(savedTime.minutes, Eq(originalTime.minutes));
	ASSERT_THAT(savedTime.hours, Eq(originalTime.hours));
}
