#ifndef SCENE_STATE_MACHINE_HPP
#define SCENE_STATE_MACHINE_HPP

#include <memory>
#include <unordered_map>
#include "scene.hpp"
#include "window.hpp"

class SceneStateMachine {
public:
	SceneStateMachine();
	void ProcessInput();
	void Update(float time_step);
	void LateUpdate(float time_step);
	unsigned int Add(std::shared_ptr<Scene> scene);
	void SwitchTo(unsigned int id);
	void Remove(unsigned int id);
	void Draw(Window& window);

private:
	std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
	std::shared_ptr<Scene> curScene;
	unsigned int insertedSceneID;
};

SceneStateMachine::SceneStateMachine() : scenes(0), curScene(0) { }

void SceneStateMachine::ProcessInput() {
	if (curScene) {
		curScene->ProcessInput();
	}
}

void SceneStateMachine::Update(float time_step) {
	if (curScene) {
		curScene->Update(time_step);
	}
}

void SceneStateMachine::LateUpdate(float time_step) {
	if (curScene) {
		curScene->LateUpdate(time_step);
	}
}

void SceneStateMachine::Draw(Window& window) {
	if (curScene) {
		curScene->Draw(window);
	}
}

unsigned int SceneStateMachine::Add(std::shared_ptr<Scene> scene) {
	auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));
	insertedSceneID++;
	inserted.first->second->OnCreate();
	return insertedSceneID - 1;
}

void SceneStateMachine::SwitchTo(unsigned int id) {
	auto it = scenes.find(id);
	if (it != scenes.end()) {
		if (curScene) {
			curScene->OnDeactivate();
		}
		curScene = it->second;
		curScene->OnActivate();
	}
}

void SceneStateMachine::Remove(unsigned int id) {
	auto it = scenes.find(id);
	if (it != scenes.end()) {
		if (curScene == it->second) {
			curScene = nullptr;
		}
		it->second->OnDestroy();
		scenes.erase(it);
	}
}

#endif // !SCENE_STATE_MACHINE_HPP