#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include "..//..//Datatypes/Rect.hpp"
#include "..//..//Datatypes/Mat.hpp"
#include "..//Component.hpp"
#include "..//GameObject.hpp"

#include <cmath>
#include <memory>

class Collider : public Component {
public:
	Collider(GameObject* owner);

	Rect getBound() const;

	void update(float time_step) override;

	bool contains(const Rect& other) const;
	bool contains(std::shared_ptr<Collider> other) const;
	bool collides(const Rect& other) const;
	bool collides(std::shared_ptr<Collider> other) const;

	void setPosition(vec<2> pos);
	void setSize(vec<2> size);

private:
	vec<2> bound_pos;
	vec<2> bound_siz;
	Rect bound;
};

inline Collider::Collider(GameObject* owner) :
	Component(owner), bound_pos(0.0f, 0.0f), bound_siz(1.0f, 1.0f),
	bound({owner->transform->getPosition() + bound_pos * owner->transform->getScale() },
		{owner->transform->getScale() * bound_siz}) {}

inline Rect Collider::getBound() const {
	return bound;
}

inline void Collider::update(float time_step) {
	bound.centre = { owner->transform->getPosition() + bound_pos * owner->transform->getScale() };
	bound.span = { owner->transform->getScale() * bound_siz };
}

inline bool Collider::contains(const Rect& other) const {
	return getBound().contains(other);
}

inline bool Collider::contains(std::shared_ptr<Collider> other) const {
	return getBound().contains(other->getBound());
}

inline bool Collider::collides(const Rect& other) const {
	return getBound().overlaps(other);
}

inline bool Collider::collides(std::shared_ptr<Collider> other) const {
	return getBound().overlaps(other->getBound());
}

inline void Collider::setPosition(vec<2> pos) {
	bound_pos = pos;
}

inline void Collider::setSize(vec<2> size) {
	bound_siz = size;
}

#endif // !COLLIDER_HPP
