#ifndef SCENE_STATE_MACHINE_HPP
#define SCENE_STATE_MACHINE_HPP

#include <memory>
#include <unordered_map>
#include "./Scene.hpp"
#include "./Window.hpp"

class SceneStateMachine {
public:
	SceneStateMachine();
	void captureInput();
	void update(float time_step);
	void lateUpdate(float time_step);
	unsigned int addScene(std::shared_ptr<Scene> scene);
	void switchToScene(unsigned int id);
	void removeScene(unsigned int id);
	void draw(Window& window);

private:
	std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
	std::shared_ptr<Scene> active_scene;
	unsigned int inserted_scene_id;
};

SceneStateMachine::SceneStateMachine() : scenes(0), active_scene(0) { }

void SceneStateMachine::captureInput() {
	if (active_scene) {
		active_scene->captureInput();
	}
}

void SceneStateMachine::update(float time_step) {
	if (active_scene) {
		active_scene->update(time_step);
	}
}

void SceneStateMachine::lateUpdate(float time_step) {
	if (active_scene) {
		active_scene->lateUpdate(time_step);
	}
}

void SceneStateMachine::draw(Window& window) {
	if (active_scene) {
		active_scene->draw(window);
	}
}

unsigned int SceneStateMachine::addScene(std::shared_ptr<Scene> scene) {
	auto inserted = scenes.insert(std::make_pair(inserted_scene_id, scene));
	inserted_scene_id++;
	inserted.first->second->onCreate();
	return inserted_scene_id - 1;
}

void SceneStateMachine::switchToScene(unsigned int id) {
	auto it = scenes.find(id);
	if (it != scenes.end()) {
		if (active_scene) {
			active_scene->onDeactivate();
		}
		active_scene = it->second;
		active_scene->onActivate();
	}
}

void SceneStateMachine::removeScene(unsigned int id) {
	auto it = scenes.find(id);
	if (it != scenes.end()) {
		if (active_scene == it->second) {
			active_scene = nullptr;
		}
		it->second->onDestroy();
		scenes.erase(it);
	}
}

#endif // !SCENE_STATE_MACHINE_HPP