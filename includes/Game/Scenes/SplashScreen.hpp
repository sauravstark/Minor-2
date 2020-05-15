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
};

SceneSplashScreen::SceneSplashScreen(SceneStateMachine& scene_state_machine)
	: scene_state_machine(scene_state_machine), switch_to_state(0),
	current_seconds(0.f), show_for_seconds(2.0f){ }

void SceneSplashScreen::onCreate() {
	const unsigned int count = 2;
	const unsigned int row_count = 9 * count;
	const unsigned int col_count = 16 * count;
	const float l = 2.0f / col_count;
	const float b = 2.0f / row_count;
	for (int i = 0; i < 8; ++i) {
		player[i] = createObject();

		auto transform = player[i]->getComponent<Transform>();
		transform->setScale(50.0f, 50.0f);

		auto texture = player[i]->addComponent<Texture>();
		texture->set(0);

		auto animation = player[i]->addComponent<Animation>();
		std::shared_ptr<FrameSet> floating_animation = std::make_shared<FrameSet>(3, Repeat::ALTERNATE);
		floating_animation->setFrameData(0, Frame(SpriteSheet::Enemy::flying_1));
		floating_animation->setFrameData(1, Frame(SpriteSheet::Enemy::flying_2));
		floating_animation->setFrameData(2, Frame(SpriteSheet::Enemy::flying_3));
		animation->addAnimation("FLY", floating_animation);
		animation->setAnimation("FLY");
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

	auto x_pos = [](float t) {
		return sinf(1 * t * PI / 3 + PI / 2) * 200;
	};
	auto y_pos = [](float t) {
		return sinf(2 * t * PI / 3) * 200;
	};
	for (int i = 0; i < 8; ++i) {
		float phase = current_seconds + float(i) * 3.0f / 8;
		player[i]->getComponent<Transform>()->setPos(x_pos(phase), y_pos(phase));
	}
}

#endif // !SCENE_SPLASH_SCREEN_HPP