#include "Timer.h"

Timer::Timer()
{
	m_time_start = std::chrono::steady_clock::now();
}

void Timer::stop()
{
	m_time_end = std::chrono::steady_clock::now();
	m_time_elapsed = m_time_end - m_time_start;
}