#ifndef SCENE_HPP
#define SCENE_HPP

#include "..//GameEngine/ObjectCollection.hpp"
#include "./Window.hpp"
#include <memory>

class Scene {
protected:
public:
	virtual void onCreate() = 0;
	virtual void onDestroy() = 0;
	virtual void onActivate() {};
	virtual void onDeactivate() {};
	virtual void captureInput() {};
	virtual void update(float time_step) {};
	void postUpdate(float time_step);
	virtual void lateUpdate(float time_step) {};
	void draw(Window& window);
	std::shared_ptr<GameObject> createObject();
	void destroyObject(std::shared_ptr<GameObject>);
private:
	ObjectCollection object_collection;
};

inline void Scene::postUpdate(float time_step) {
	object_collection.processRemovedObjects();
	object_collection.processAddedObjects();
	object_collection.update(time_step);
	object_collection.lateUpdate(time_step);
}

void Scene::draw(Window& window) {
	object_collection.calculateVertices();
	object_collection.draw(window);
}

inline std::shared_ptr<GameObject> Scene::createObject() {
	auto new_object = std::make_shared<GameObject>();
	object_collection.add(new_object);
	return new_object;
}

inline void Scene::destroyObject(std::shared_ptr<GameObject> object) {
	object_collection.remove(object);
}

#endif // !SCENE_HPP