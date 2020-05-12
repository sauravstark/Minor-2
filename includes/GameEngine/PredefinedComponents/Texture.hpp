#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "..//Component.hpp"
#include "..//..//Datatypes/Vec.hpp"

class Texture : public Component {
public:
	Texture(GameObject* owner);
	void set(int tex);
	void setColor(float r, float g, float b, float a);
	void setColor(vec<4> color);
	void setColor(char* hex);
	void setSprite(float str_x, float str_y, float span_x, float span_y);
	void setSprite(vec<4> sub_sprite);
	int getTextureID() const;
	const vec<4>& getColor() const;
	const vec<4>& getSprite() const;
private:
	vec<4> color;
	int texture;
	vec<4> tex_span;
};

inline Texture::Texture(GameObject* owner) :
	Component(owner), texture(-1), color(1.0f, 1.0f, 1.0f, 1.0f),
	tex_span(0.0f, 0.0f, 1.0f, 1.0f) {}

inline void Texture::set(int tex) {
	texture = tex;
}

inline void Texture::setColor(float r, float g, float b, float a) {
	color = { r, g, b, a };
}

inline void Texture::setColor(vec<4> color) {
	this->color = color;
}

inline void Texture::setColor(char* hex) {
	color = { 1.0f, 1.0f, 1.0f, 1.0f };
}

inline void Texture::setSprite(float str_x, float str_y, float span_x, float span_y) {
	tex_span = { str_x, str_y, str_x + span_x, str_y + span_y };
}

inline void Texture::setSprite(vec<4> sub_sprite) {
	tex_span = sub_sprite;
}

inline int Texture::getTextureID() const {
	return texture;
}

inline const vec<4>& Texture::getColor() const {
	return color;
}

inline const vec<4>& Texture::getSprite() const {
	return tex_span;
}

#endif // !TEXTURE_HPP
