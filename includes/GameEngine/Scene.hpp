#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "../Datatypes/Vertex.hpp"
#include "./Window.hpp"

class Scene {
protected:
	std::vector<Vertex> vertices;
public:
	virtual void onCreate() = 0;
	virtual void onDestroy() = 0;
	virtual void onActivate() {};
	virtual void onDeactivate() {};
	virtual void captureInput() {};
	virtual void update(float time_step) {};
	virtual void lateUpdate(float time_step) {};
	void draw(Window& window);
};

void Scene::draw(Window& window) {
	window.draw(vertices);
}

#endif // !SCENE_HPP