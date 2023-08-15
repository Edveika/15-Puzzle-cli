#pragma once
#include <chrono>

class Timer
{
private:
	std::chrono::time_point<std::chrono::steady_clock> m_time_start;
	std::chrono::time_point<std::chrono::steady_clock> m_time_end;
	std::chrono::duration<double> m_time_elapsed;

public:
	Timer();

	void stop();
	double get_time_elapsed() { return m_time_elapsed.count(); }
};