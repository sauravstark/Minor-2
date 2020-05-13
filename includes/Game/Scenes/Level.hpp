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
	std::shared_ptr<GameObject> player1;
};

void SceneGame::onCreate() {
	const unsigned int count = 2;
	const unsigned int row_count = 9 * count;
	const unsigned int col_count = 16 * count;
	const float l = 2.0f / col_count;
	const float b = 2.0f / row_count;

	player1 = std::make_shared<GameObject>();

	auto transform = player1->getComponent<Transform>();
	transform->setPos(-0.5f, -0.5f);
	transform->setScale(l, b);

	auto sprite = player1->addComponent<Texture>();
	sprite->set(0);

	auto animation = player1->addComponent<Animation>();
	std::shared_ptr<FrameSet> flying_animation = std::make_shared<FrameSet>(3, Repeat::ALTERNATE);
	flying_animation->setFrameData(0, Frame(SpriteSheet::Enemy::spikey_1));
	flying_animation->setFrameData(1, Frame(SpriteSheet::Enemy::spikey_2));
	flying_animation->setFrameData(2, Frame(SpriteSheet::Enemy::spikey_3));
	animation->addAnimation("MOVE", flying_animation);
	animation->setAnimation("MOVE");

	object_collection.add(player1);
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
