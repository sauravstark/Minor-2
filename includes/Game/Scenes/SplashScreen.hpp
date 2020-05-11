#ifndef SCENE_SPLASH_SCREEN_HPP
#define SCENE_SPLASH_SCREEN_HPP

#include "../../Datatypes/Object.hpp"
#include "../../GameEngine/SceneStateMachine.hpp"

class SceneSplashScreen : public Scene
{
public:
	SceneSplashScreen(SceneStateMachine& scene_state_machine, Window& window);
	void onCreate() override;
	void onDestroy() override;
	void onActivate() override;
	void setSwitchToScene(unsigned int id);
	void update(float time_step) override;
private:
	Object player;
	int stage;
	SceneStateMachine& scene_state_machine;
	Window& window;
	float show_for_seconds;
	float current_seconds;
	unsigned int switch_to_state;
};

SceneSplashScreen::SceneSplashScreen(SceneStateMachine& scene_state_machine, Window& window)
	: scene_state_machine(scene_state_machine),	window(window), switch_to_state(0),
	current_seconds(0.f), show_for_seconds(5.f), stage(1) { }

void SceneSplashScreen::onCreate() {
	const unsigned int count = 2;
	const unsigned int row_count = 9 * count;
	const unsigned int col_count = 16 * count;
	const float l = 2.0f / col_count;
	const float b = 2.0f / row_count;
	player.setScale(vec<2>(l * 4, b * 4))
		.setTexture(0, { 0.0f / 16, 15.0f / 16 }, { 1.0f / 16, 16.0f / 16 })
		.setPosition(vec<2>(0.0f, 0.0f));
	std::tuple<Vertex, Vertex, Vertex, Vertex> v = player.getVertices();
	vertices.push_back(std::get<0>(v));
	vertices.push_back(std::get<1>(v));
	vertices.push_back(std::get<2>(v));
	vertices.push_back(std::get<3>(v));
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

	int slot = int(current_seconds / 0.25f) % 4;
	if (slot < 2) {
		stage = slot;
	} else {
		stage = 4 - slot;
	}

	player.setTexture(0, { (0.0f + stage) / 16, 15.0f / 16 }, { (1.0f + stage) / 16, 16.0f / 16 });
	std::tuple<Vertex, Vertex, Vertex, Vertex> v = player.getVertices();
	vertices[0] = std::get<0>(v);
	vertices[1] = std::get<1>(v);
	vertices[2] = std::get<2>(v);
	vertices[3] = std::get<3>(v);
}

#endif // !SCENE_SPLASH_SCREEN_HPP