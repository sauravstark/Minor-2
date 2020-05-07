#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "vertex.hpp"
#include "window.hpp"

class Scene {
protected:
	std::vector<Vertex> vertices;
public:
	virtual void OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void OnActivate() {};
	virtual void OnDeactivate() {};
	virtual void ProcessInput() {};
	virtual void Update(float time_step) {};
	virtual void LateUpdate(float time_step) {};
	void Draw(Window& window);
};

void Scene::Draw(Window& window) {
	window.draw(vertices);
}

#endif // !SCENE_HPP