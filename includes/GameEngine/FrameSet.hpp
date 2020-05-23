#ifndef FRAME_SET_HPP
#define FRAME_SET_HPP

#include "..//Datatypes/Vec.hpp"
#include <vector>

enum Repeat { FORWARD, REVERSE, ALTERNATE, ALTERNATE_REVERSE };

struct Frame {
	vec<4> frame_span;
	float frame_duration;
	Frame(vec<4> span = vec<4>(), float duration = 0.125f);
};

class FrameSet {
public:
	FrameSet(unsigned frame_count, Repeat repeat = Repeat::ALTERNATE);
	const vec<4> getCurrentFrame() const;
	void setFrameData(unsigned slot, const Frame& frame);
	void setRepeat(Repeat dir);
	Repeat getRepeat() const;
	void update(float time_step);
	void reset();
private:
	std::vector<Frame> frames;
	int active_frame_index;
	int incr;
	float time_elapsed;
	Repeat repeat_function;

	void nextFrame();
};

inline Frame::Frame(vec<4> span, float duration) :
	frame_span(span), frame_duration(duration) {}

inline FrameSet::FrameSet(unsigned frame_count, Repeat repeat) :
	frames(frame_count), time_elapsed(0.0f),
	repeat_function(repeat) {

	if (repeat_function == Repeat::FORWARD || repeat_function == Repeat::ALTERNATE) {
		active_frame_index = 0;
		incr = 1;
	} else {
		active_frame_index = frame_count - 1;
		incr = -1;
	}
}

inline const vec<4> FrameSet::getCurrentFrame() const {
	return frames[active_frame_index].frame_span;
}

inline void FrameSet::setFrameData(unsigned slot, const Frame& frame) {
	if (slot < frames.size())
		frames[slot] = frame;
}

inline void FrameSet::setRepeat(Repeat repeat) {
	repeat_function = repeat;
}

inline Repeat FrameSet::getRepeat() const {
	return repeat_function;
}

inline void FrameSet::update(float time_step) {
	if (frames.size() > 1) {
		time_elapsed += time_step;

		if (time_elapsed > frames[active_frame_index].frame_duration)
			nextFrame();
	}
}

inline void FrameSet::nextFrame() {
	time_elapsed = 0.0f;
	active_frame_index += incr;
	if (repeat_function == Repeat::FORWARD && active_frame_index == frames.size()) {
		active_frame_index = 0;
	} else if (repeat_function == Repeat::REVERSE && active_frame_index == -1) {
		active_frame_index = frames.size() - 1;
	} else if ((repeat_function == Repeat::ALTERNATE || repeat_function == Repeat::ALTERNATE_REVERSE) && active_frame_index == frames.size()) {
		active_frame_index = frames.size() - 2;
		incr = -1;
	} else if ((repeat_function == Repeat::ALTERNATE || repeat_function == Repeat::ALTERNATE_REVERSE) && active_frame_index == -1) {
		active_frame_index = 1;
		incr = 1;
	}
}

inline void FrameSet::reset() {
	time_elapsed = 0.0f;
	if (repeat_function == Repeat::FORWARD || repeat_function == Repeat::ALTERNATE) {
		active_frame_index = 0;
		incr = 1;
	}
	else {
		active_frame_index = frames.size() - 1;
		incr = -1;
	}
}

#endif // !FRAME_SET_HPP
