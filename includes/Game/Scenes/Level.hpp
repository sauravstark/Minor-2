#ifndef SCENE_GAME_HPP
#define SCENE_GAME_HPP

#include "../../GameEngine/Scene.hpp"
#include "../../GameEngine/Input.hpp"
#include "..//..//GameEngine/GameObject.hpp"
#include "..//..//GameEngine/PredefinedComponents/KeyboardMovement.hpp"
#include "..//..//GameEngine/PredefinedComponents/Texture.hpp"
#include "..//..//GameEngine/ObjectCollection.hpp"

#include <cstdlib>

#define TAU 6.2832
struct Tex { vec<2> x; vec<2> y; };

class SceneGame : public Scene
{
public:
	void onCreate() override;
	void onDestroy() override;
	void captureInput() override;
	void update(float time_step) override;
	void lateUpdate(float time_step) override;
private:
	Input input;
private:
	ObjectCollection object_collection;
};

void SceneGame::onCreate() {
	std::shared_ptr<GameObject> player = std::make_shared<GameObject>();

	auto sprite = player->addComponent<Texture>();
	sprite->set(0);
	sprite->setSprite({ 0.0f / 16, 14.0f / 16, 1.0f / 16, 15.0f / 16 });

	object_collection.add(player);
}

void SceneGame::onDestroy() {

}

void SceneGame::captureInput() {
	input.updateInput();
}

void SceneGame::update(float time_step) {
	object_collection.processRemovedObjects();
	object_collection.processAddedObjects();
	object_collection.update(time_step);
}

inline void SceneGame::lateUpdate(float time_step) {
	object_collection.lateUpdate(time_step);
	object_collection.calculateVertices(vertices);
}

#endif // !SCENE_GAME_HPP
