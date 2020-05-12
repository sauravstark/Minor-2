#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class GameObject;

class Component {
public:
	Component(GameObject* owner) : owner(owner) {}

	virtual void awake() {};
	virtual void start() {};

	virtual void update(float deltaTime) {};
	virtual void lateUpdate(float deltaTime) {};
	virtual void draw(Window& window) {};

protected:
	GameObject* owner;
};

#endif // !COMPONENT_HPP
