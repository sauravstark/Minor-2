#ifndef SCENE_SPLASH_SCREEN_HPP
#define SCENE_SPLASH_SCREEN_HPP

#include "..//..//GameEngine/ObjectCollection.hpp"
#include "..//..//GameEngine/SceneStateMachine.hpp"
#include "..//..//GameEngine/PredefinedComponents/Transform.hpp"
#include "..//..//GameEngine/PredefinedComponents/Texture.hpp"
#include "..//..//GameEngine/PredefinedComponents/Animation.hpp"
#include "..//Sprites/SpriteSheet.hpp"
#include <memory>

class SceneSplashScreen : public Scene
{
public:
	SceneSplashScreen(SceneStateMachine& scene_state_machine);
	void onCreate() override;
	void onDestroy() override;
	void onActivate() override;
	void setSwitchToScene(unsigned int id);
	void update(float time_step) override;
private:
	std::shared_ptr<GameObject> player;
	SceneStateMachine& scene_state_machine;
	float show_for_seconds;
	float current_seconds;
	unsigned int switch_to_state;
	float box_size = 100.0f;
};

SceneSplashScreen::SceneSplashScreen(SceneStateMachine& scene_state_machine)
	: scene_state_machine(scene_state_machine), switch_to_state(0),
	current_seconds(0.f), show_for_seconds(4.0f){ }

void SceneSplashScreen::onCreate() {
	player = createObject();
	auto transform = player->getComponent<Transform>();
	transform->setScale(box_size, box_size);
	transform->setRot(-PI / 2);
	auto texture = player->addComponent<Texture>();
	texture->set(0);
	player->getComponent<Texture>()->setSprite(SpriteSheet::Player::red_fighter5);
}

void SceneSplashScreen::onActivate() {
	current_seconds = 0.f;
}

void SceneSplashScreen::onDestroy() { }

void SceneSplashScreen::setSwitchToScene(unsigned int id) {
	switch_to_state = id;
}

void SceneSplashScreen::update(float time_step) {
	current_seconds += time_step;

	if (current_seconds >= show_for_seconds) {
		scene_state_machine.switchToScene(switch_to_state);
	}

	player->getComponent<Transform>()->setX(-800.0f * cosf(PI * current_seconds / show_for_seconds));
}

#endif // !SCENE_SPLASH_SCREEN_HPP