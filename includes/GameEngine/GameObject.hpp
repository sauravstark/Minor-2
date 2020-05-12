#ifndef GAME_GameObject_HPP
#define GAME_GameObject_HPP

#include "./Window.hpp"
#include "./Component.hpp"
#include "./PredefinedComponents/Transform.hpp"
#include <memory>
#include <vector>

class GameObject {
public:
	GameObject();
	void awake();
	void start();

	void update(float deltaTime);
	void lateUpdate(float deltaTime);
	void draw(Window& window);

	template <typename T> std::shared_ptr<T> addComponent();
	template <typename T> std::shared_ptr<T> getComponent();

	std::shared_ptr<Transform> transform;

private:
	std::vector<std::shared_ptr<Component>> components;
};

GameObject::GameObject() {
	transform = addComponent<Transform>();
}

void GameObject::awake() {
	for (int i = components.size() - 1; i >= 0; i--) {
		components[i]->awake();
	}
}

void GameObject::start() {
	for (int i = components.size() - 1; i >= 0; i--) {
		components[i]->start();
	}
}

void GameObject::update(float timeDelta) {
	for (int i = components.size() - 1; i >= 0; i--) {
		components[i]->update(timeDelta);
	}
}

void GameObject::lateUpdate(float timeDelta) {
	for (int i = components.size() - 1; i >= 0; i--) {
		components[i]->lateUpdate(timeDelta);
	}
}

void GameObject::draw(Window& window) {
	for (int i = components.size() - 1; i >= 0; i--) {
		components[i]->draw(window);
	}
}

template <typename T> std::shared_ptr<T> GameObject::addComponent() {
	static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
		
		for (auto& existing_component : components) {			
			if (std::dynamic_pointer_cast<T>(existing_component))
				return std::dynamic_pointer_cast<T>(existing_component);
		}	
	
	std::shared_ptr<T> new_component = std::make_shared<T>(this);
	components.push_back(new_component);

	return new_component;
};

template <typename T> std::shared_ptr<T> GameObject::getComponent() {
	static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");		
		for (auto& existing_component : components) {
			if (std::dynamic_pointer_cast<T>(existing_component))
				return std::dynamic_pointer_cast<T>(existing_component);
		}

	return nullptr;
};

#endif 
