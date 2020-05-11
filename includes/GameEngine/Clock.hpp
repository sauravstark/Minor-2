#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <chrono>

class Clock{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> last_capture;
public:
	Clock();
	float getTimeStep();
};

Clock::Clock() : last_capture(std::chrono::high_resolution_clock::now()) {}

float Clock::getTimeStep(){
	std::chrono::time_point<std::chrono::high_resolution_clock> new_capture = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> time_step = new_capture - last_capture;
	last_capture = new_capture;
	return time_step.count();
}

#endif // !CLOCK_HPP