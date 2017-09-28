#include "Time.h"

#include <chrono>
#include "Logger.h"

float Time::time;
float Time::delta;

void Time::Update ()
{
	float last_time = Time::time;
	uint64_t actual_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	static uint64_t start_time = actual_time;
	Time::time = (float)((double)(actual_time - start_time) / 1000.0 / 1000.0);
	Time::delta = time - last_time;
	
	
	// printf ("Time: %f\n", Time::time);
	// printf ("Delta: %f\n", Time::delta);
}