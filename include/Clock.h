#ifndef _CLOCK_H
#define _CLOCK_H

class Time{
	public:
		Time(int hours, int minutes, int seconds, int milliseconds){
			this->hours = hours;	
			this->minutes = minutes;	
			this->seconds = seconds;	
			this->milliseconds = milliseconds;	
		}
		int milliseconds;
		int seconds;
		int minutes;
		int hours;
};

class Clock{
	int timeAsInt;
	public:
		Clock(void);
		int getTimeAsInt(void);
		void tick(void);
		void setTime(Time& newTime);
		void getTime(Time& newTime) const;
};
#endif //CLOCK_H
