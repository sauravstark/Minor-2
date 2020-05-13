#ifndef SCENE_GAME_HPP
#define SCENE_GAME_HPP

#include "..//..//GameEngine/Scene.hpp"
#include "..//..//GameEngine/Input.hpp"
#include "..//..//GameEngine/GameObject.hpp"
#include "..//..//GameEngine/ObjectCollection.hpp"
#include "..//..//GameEngine/PredefinedComponents/Texture.hpp"
#include "..//..//GameEngine/PredefinedComponents/Animation.hpp"
#include "..//Sprites/SpriteSheet.hpp"

#include <cstdlib>

#define TAU 6.2832
struct Tex { vec<2> x; vec<2> y; };

class SceneGame : public Scene {
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

	auto animation = player->addComponent<Animation>();
	std::shared_ptr<FrameSet> flying_animation = std::make_shared<FrameSet>(3, Repeat::ALTERNATE);
	flying_animation->setFrameData(0, Frame(SpriteSheet::Enemy::spikey_1));
	flying_animation->setFrameData(1, Frame(SpriteSheet::Enemy::spikey_2));
	flying_animation->setFrameData(2, Frame(SpriteSheet::Enemy::spikey_3));
	animation->addAnimation("MOVE", flying_animation);
	animation->setAnimation("MOVE");

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
