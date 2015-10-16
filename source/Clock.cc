#include "Clock.h"

Clock::Clock(void){
	this->timeAsInt = 0;
}

int Clock::getTimeAsInt(void){
	return this->timeAsInt;
}

void Clock::tick(void){
	int tempTime = this->timeAsInt;
	tempTime++;
	tempTime%=(24*60*60*1000);
	this->timeAsInt = tempTime;
}

void Clock::setTime(Time& newTime){
	int tempNewTime = (newTime.hours * 60 * 60 * 1000) +
		(newTime.minutes * 60 * 1000) +
		(newTime.seconds * 1000) +
		newTime.milliseconds;
	tempNewTime %= (24*60*60*1000);
	this->timeAsInt = tempNewTime;
}

void Clock::getTime(Time& newTime) const{
	int timeSnapshot = this->timeAsInt;
	int hours = timeSnapshot/(1000*60*60);
	timeSnapshot = timeSnapshot - (hours * (1000*60*60));

	int minutes = timeSnapshot/(1000*60);
	timeSnapshot = timeSnapshot - (minutes * (1000*60));

	int seconds = timeSnapshot/(1000);
	timeSnapshot = timeSnapshot - (seconds * (1000));

	int milliseconds = timeSnapshot;

	newTime.milliseconds = milliseconds ;
	newTime.seconds = seconds;
	newTime.minutes = minutes;
	newTime.hours = hours;
}

