#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <chrono>

class Clock{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
	Clock();
	float getTimeStep();
};

Clock::Clock() : start(std::chrono::high_resolution_clock::now()) {
}

float Clock::getTimeStep(){
	std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> time_step = now - start;
	start = now;
	return time_step.count();
}

#endif // !CLOCK_HPP