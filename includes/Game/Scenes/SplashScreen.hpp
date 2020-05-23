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
	std::shared_ptr<GameObject> player[8];
	SceneStateMachine& scene_state_machine;
	float show_for_seconds;
	float current_seconds;
	unsigned int switch_to_state;
	float box_size = 100.0f;
};

SceneSplashScreen::SceneSplashScreen(SceneStateMachine& scene_state_machine)
	: scene_state_machine(scene_state_machine), switch_to_state(0),
	current_seconds(0.f), show_for_seconds(10.0f){ }

void SceneSplashScreen::onCreate() {
	for (int i = 0; i < 8; ++i) {
		player[i] = createObject();
		auto transform = player[i]->getComponent<Transform>();
		transform->setScale(box_size, box_size);
		
		auto texture = player[i]->addComponent<Texture>();
		texture->set(0);
		
		auto frameset = std::make_shared<FrameSet>(3, Repeat::FORWARD);
		frameset->setFrameData(0, SpriteSheet::Enemy::flying_1);
		frameset->setFrameData(1, SpriteSheet::Enemy::flying_2);
		frameset->setFrameData(2, SpriteSheet::Enemy::flying_3);
		
		auto animation = player[i]->addComponent<Animation>();
		animation->addAnimation("move", frameset);
		animation->setAnimation("move");
	}
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

	auto lissajous = [](float angle, float phase) {
		float t = angle + phase * 2 * PI;
		float x = sinf(t * 3 + PI / 2) * 300.0f;
		float y = sinf(t * 2) * 300.0f;
		return vec<2>(x,y);
	};

	for (int i = 0; i < 8; ++i)
		player[i]->getComponent<Transform>()->setPos(lissajous(current_seconds, float(i) / 32));
}

#endif // !SCENE_SPLASH_SCREEN_HPP