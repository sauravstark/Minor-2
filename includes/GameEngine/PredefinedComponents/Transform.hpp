#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "../Component.hpp"
#include "../../Datatypes/Vec.hpp"

class Transform : public Component {
public:
	Transform(GameObject* owner);

	void set(float x, float y);
	void set(vec<2> pos);

	void move(float x, float y);
	void move(vec<2> pos);

	void setX(float x);
	void setY(float y);

	void moveX(float x);
	void moveY(float y);

	const vec<2>& getPosition() const;
private:
	vec<2> position;
};

Transform::Transform(GameObject *owner) :
	Component(owner), position(0.0f, 0.0f) {}

void Transform::set(float x, float y) {
	position = { x , y };
}

void Transform::set(vec<2> pos) {
	position = pos;
}

void Transform::move(float x, float y) {
	position[0] += x;
	position[1] += y;
}

void Transform::move(vec<2> step) {
	position[0] += step[0];
	position[1] += step[1];
}

void Transform::setX(float x) {
	position[0] = x;
}

void Transform::setY(float y) {
	position[1] = y;
}

void Transform::moveX(float x) {
	position[0] += x;
}

void Transform::moveY(float y) {
	position[1] += y;
}

const vec<2>& Transform::getPosition() const {
	return position;
}

#endif // !TRANSFORM_HPP
