#ifndef SCENE_SPLASH_SCREEN_HPP
#define SCENE_SPLASH_SCREEN_HPP

#include "object.hpp"
#include "scenestatemachine.hpp"

class SceneSplashScreen : public Scene
{
public:
	SceneSplashScreen(SceneStateMachine& sceneStateMachine, Window& window);
	void OnCreate() override;
	void OnDestroy() override;
	void OnActivate() override;
	void SetSwitchToScene(unsigned int id);
	void Update(float time_step) override;
private:
	Object player;
	SceneStateMachine& sceneStateMachine;
	Window& window;
	float showForSeconds;
	float currentSeconds;
	unsigned int switchToState;
};

SceneSplashScreen::SceneSplashScreen(SceneStateMachine& sceneStateMachine, Window& window)
	: sceneStateMachine(sceneStateMachine),	window(window), switchToState(0),
	currentSeconds(0.f), showForSeconds(3.f)
{}

void SceneSplashScreen::OnCreate() {
	const unsigned int count = 2;
	const unsigned int row_count = 9 * count;
	const unsigned int col_count = 16 * count;
	const float l = 2.0f / col_count;
	const float b = 2.0f / row_count;
	player.setScale(vec<2>(l, b)).setTexture(9).setPosition(vec<2>(0.0f, 0.0f));
	std::tuple<Vertex, Vertex, Vertex, Vertex> v = player.getVertices();
	vertices.push_back(std::get<0>(v));
	vertices.push_back(std::get<1>(v));
	vertices.push_back(std::get<2>(v));
	vertices.push_back(std::get<3>(v));
}

void SceneSplashScreen::OnActivate() {
	currentSeconds = 0.f;
}

void SceneSplashScreen::OnDestroy() { }

void SceneSplashScreen::SetSwitchToScene(unsigned int id) {
	switchToState = id;
}

void SceneSplashScreen::Update(float time_step) {
	currentSeconds += time_step;

	if (currentSeconds >= showForSeconds) {
		sceneStateMachine.SwitchTo(switchToState);
	}
}

#endif // !SCENE_SPLASH_SCREEN_HPP