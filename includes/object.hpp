#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <tuple>
#include <cmath>
#include "vec.hpp"
#include "mat.hpp"
#include "vertex.hpp"

class Object {
private:
    unsigned long long int id;
	vec<2> position;
	vec<1> rotation;
	vec<2> scale;
	vec<4> color;
public:
	Object();
    unsigned long long int getID() const;
	Object& setPosition(vec<2> pos);
	Object& setRotation(vec<1> rot);
	Object& setScale(vec<2> sca);
	Object& setColor(vec<4> col);
	vec<2> getPosition() const;
	vec<1> getRotation() const;
	vec<2> getScale() const;
	vec<4> getColor() const;
	std::tuple<Vertex, Vertex, Vertex, Vertex> getVertices() const;
};

Object::Object() :
	position(vec<2>(0.0f, 0.0f)),
	color(vec<4>(1.0f, 0.0f, 0.0f, 1.0f)),
	rotation(vec<1>(0.0f)),
	scale(vec<2>(1.0f, 1.0f)) { }

unsigned long long int Object::getID() const {
    return id;
}

Object& Object::setPosition(vec<2> pos) {
	position = pos;
	return *this;
}

Object& Object::setRotation(vec<1> rot) {
	rotation = rot;
	return *this;
}

Object& Object::setScale(vec<2> sca) {
	scale = sca;
	return *this;
}

Object& Object::setColor(vec<4> col) {
	color = col;
	return *this;
}

vec<2> Object::getPosition() const {
	return position;
}

vec<1> Object::getRotation() const {
	return rotation;
}

vec<2> Object::getScale() const {
	return scale;
}

vec<4> Object::getColor() const {
	return color;
}

std::tuple<Vertex, Vertex, Vertex, Vertex> Object::getVertices() const {
	mat<3> translation, rotation, scale;

	vec<2> pos = this->position;
	vec<1> rot = this->rotation;
	vec<2> sca = this->scale;
	vec<4> col = this->color;

	translation[0][2] = pos[0];
	translation[1][2] = pos[1];

	rotation[0][0] =  cos(rot[0]);
	rotation[0][1] = -sin(rot[0]);
	rotation[1][0] =  sin(rot[0]);
	rotation[1][1] =  cos(rot[0]);

	scale[0][0] = sca[0];
	scale[1][1] = sca[1];

	mat<3> transform = translation * rotation * scale;

	Vertex ret[4];
	
	ret[0] = { transform * vec<3>(-0.5, -0.5, 1.0), col };
	ret[1] = { transform * vec<3>( 0.5, -0.5, 1.0), col };
	ret[2] = { transform * vec<3>(-0.5,  0.5, 1.0), col };
	ret[3] = { transform * vec<3>( 0.5,  0.5, 1.0), col };

	return std::make_tuple(ret[0], ret[1], ret[2], ret[3]);
}

#endif // !OBJECT_HPP