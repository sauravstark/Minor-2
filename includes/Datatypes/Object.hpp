#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <tuple>
#include <cmath>
#include "./Vec.hpp"
#include "./Mat.hpp"
#include "./Vertex.hpp"

class Object {
private:
    unsigned long long int id;
	vec<2> position;
	vec<1> rotation;
	vec<2> scale;
	vec<4> color;
	int texture;
	vec<2> tex_str;
	vec<2> tex_end;
public:
	Object();
    unsigned long long int getID() const;
	Object& setPosition(vec<2> pos);
	Object& setRotation(vec<1> rot);
	Object& setScale(vec<2> sca);
	Object& setColor(vec<4> col);
	Object& setTexture(int tex);
	Object& setTexture(int tex, vec<2> tex_str, vec<2> tex_end);
	vec<2> getPosition() const;
	vec<1> getRotation() const;
	vec<2> getScale() const;
	vec<4> getColor() const;
	int getTexture() const;
	std::tuple<Vertex, Vertex, Vertex, Vertex> getVertices() const;
};

Object::Object() :
	position(vec<2>(0.0f, 0.0f)),
	color(vec<4>(1.0f, 1.0f, 1.0f, 1.0f)),
	rotation(vec<1>(0.0f)),
	scale(vec<2>(1.0f, 1.0f)),
	texture(-1),
	tex_str(vec<2>(0.0f, 0.0f)),
	tex_end(vec<2>(1.0f, 1.0f)) { }

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

Object& Object::setTexture(int tex) {
	texture = tex;
	return *this;
}

Object& Object::setTexture(int tex, vec<2> tex_str, vec<2> tex_end) {
	texture = tex;
	this->tex_str = tex_str;
	this->tex_end = tex_end;
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

int Object::getTexture() const {
	return texture;
}

std::tuple<Vertex, Vertex, Vertex, Vertex> Object::getVertices() const {
	mat<3> translation, rotation, scale;

	vec<2> pos = this->position;
	vec<1> rot = this->rotation;
	vec<2> sca = this->scale;
	vec<4> col = this->color;
	float  tex = float(this->texture);

	translation[0][2] = pos[0];
	translation[1][2] = pos[1];

	rotation[0][0] =  cos(rot[0]);
	rotation[0][1] = -sin(rot[0]);
	rotation[1][0] =  sin(rot[0]);
	rotation[1][1] =  cos(rot[0]);

	scale[0][0] = sca[0];
	scale[1][1] = sca[1];

	mat<3> transform = translation * scale * rotation;

	vec<2> str = tex_str, end = tex_end;
	
	Vertex ret0 = { transform * vec<3>(-0.5f, -0.5f, 1.0f), col, vec<3>(str[0], str[1], tex) };
	Vertex ret1 = { transform * vec<3>( 0.5f, -0.5f, 1.0f), col, vec<3>(end[0], str[1], tex) };
	Vertex ret2 = { transform * vec<3>(-0.5f,  0.5f, 1.0f), col, vec<3>(str[0], end[1], tex) };
	Vertex ret3 = { transform * vec<3>( 0.5f,  0.5f, 1.0f), col, vec<3>(end[0], end[1], tex) };

	return std::make_tuple(ret0, ret1, ret2, ret3);
}

#endif // !OBJECT_HPP