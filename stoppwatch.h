#ifndef _stopwatch_h
#define _stopwatch_h

#include <ctime>

class stopwatch
{
private:
	bool stopped;
	clock_t NewCount, OldCount;

public:
	double getfrequency()
	{
		return (double) CLOCKS_PER_SEC;
	};

	inline void start()
	{
		OldCount = clock();
	};
	
	stopwatch()
	{
		stopped = false;
		start();
	};
	
	inline void stop()
	{
		stopped = true;
		NewCount = clock();
	};

	double gettime()		// in ms
	{
		if(!stopped){stop();}
		return (1000*(double)((NewCount - OldCount)))/((double)CLOCKS_PER_SEC);
	};

	int randomize()
	{
		stop();
		return (int)NewCount;
	};
};

#endif
