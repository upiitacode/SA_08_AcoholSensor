#ifndef _TIMER_H
#define _TIMER_H
class Timer{
	virtual void start(void) = 0;
	virtual void stop(void) = 0;
	virtual void setPeriod(int) = 0;
};
#endif // _TIMER_H

