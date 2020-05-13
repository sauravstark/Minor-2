#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "../Component.hpp"
#include "../../Datatypes/Vec.hpp"
#include "..//..//Datatypes/Mat.hpp"

class Transform : public Component {
public:
	Transform(GameObject* owner);

	void setPos(float x, float y);
	void setPos(vec<2> pos);

	void move(float x, float y);
	void move(vec<2> pos);

	void setX(float x);
	void setY(float y);

	void moveX(float x);
	void moveY(float y);

	void setRot(float rad);
	void rotate(float rad);

	void flipX(bool flip);
	void flipY(bool flip);

	void setScale(float x, float y);
	void setScale(vec<2> scale);

	vec<2> getPosition() const;
	float getRotation() const;
	bool flippedX() const;
	bool flippedY() const;
	vec<2> getScale() const;

	const mat<3>& getTransform() const;
private:
	mat<3> transform;
};

inline Transform::Transform(GameObject *owner) :
	Component(owner),
	transform({ 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }) {}

inline void Transform::setPos(float x, float y) {
	transform[0] = { x , y, 0.0f };
}

inline void Transform::setPos(vec<2> pos) {
	transform[0] = { pos[0], pos[1], 0.0f };
}

inline void Transform::move(float x, float y) {
	transform[0][0] += x;
	transform[0][1] += y;
}

inline void Transform::move(vec<2> step) {
	transform[0][0] += step[0];
	transform[0][1] += step[1];
}

inline void Transform::setX(float x) {
	transform[0][0] = x;
}

inline void Transform::setY(float y) {
	transform[0][1] = y;
}

inline void Transform::moveX(float x) {
	transform[0][0] += x;
}

inline void Transform::moveY(float y) {
	transform[0][1] += y;
}

inline void Transform::setRot(float rad) {
	transform[1][2] = rad;
}

inline void Transform::rotate(float rad) {
	transform[1][2] += rad;
}

inline void Transform::flipX(bool flip) {
	transform[1][0] = (flip ? PI : 0.0f);
}

inline void Transform::flipY(bool flip) {
	transform[1][1] = (flip ? PI : 0.0f);
}

inline void Transform::setScale(float x, float y) {
	transform[2] = { x, y, 1.0f };
}

inline void Transform::setScale(vec<2> scale) {
	transform[1] = { scale[0], scale[1], 1.0f };
}

inline vec<2> Transform::getPosition() const {
	return { transform.get(0, 0), transform.get(0, 1) };
}

inline float Transform::getRotation() const {
	return transform.get(1, 2);
}

inline bool Transform::flippedX() const {
	return transform.get(1,0) == PI;
}

inline bool Transform::flippedY() const {
	return transform.get(2, 1) == PI;
}

inline vec<2> Transform::getScale() const {
	return { transform.get(2,0), transform.get(2,1) };
}

inline const mat<3>& Transform::getTransform() const {
	return transform;
}

#endif // !TRANSFORM_HPP
