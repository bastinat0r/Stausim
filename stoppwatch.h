#ifndef _stopwatch_h
#define _stopwatch_h

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

class stopwatch
{
private:
	bool stopped;
	struct timeval start_t, end_t;

public:
	double getfrequency()
	{
		return 42.0;
	};

	inline void start()
	{
		gettimeofday(&start_t, NULL);
	};
	
	stopwatch()
	{
		stopped = false;
		start();
	};
	
	inline void stop()
	{
		stopped = true;
		gettimeofday(&end_t, NULL);
	};

	double gettime()		// in ms
	{
		if(!stopped){stop();}
	  
		long seconds  = end_t.tv_sec  - start_t.tv_sec;
	  long useconds = end_t.tv_usec - start_t.tv_usec;

    long mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
		return mtime;
	};

	int randomize()
	{
		stop();
		return end_t.tv_usec;
	};
};

#endif
