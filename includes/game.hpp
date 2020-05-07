#ifndef GAME_HPP
#define GAME_HPP

#include "window.hpp"
#include "vertex.hpp"
#include "object.hpp"
#include "clock.hpp"
//#include "input.hpp"
#include "scenestatemachine.hpp"
#include "scenescreensplash.hpp"
#include "scenegame.hpp"
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Game {
private:
	Window window;
	Clock clock;
	//Input input;
	float time_step;
	std::vector<Vertex> vertices;
	Object player;
	SceneStateMachine scene_state_machine;
	//std::unordered_set<Object> objects;
	//std::unordered_map<unsigned long long int, unsigned long long int> index_map;
public:
	Game();
	void Update();
	void LateUpdate();
	void Draw();
	void updateTimeStep();
	void captureInput();
};

Game::Game() : time_step(0.0f){
	std::shared_ptr<SceneSplashScreen> splash_screen =
		std::make_shared<SceneSplashScreen>(scene_state_machine, window);
	std::shared_ptr<SceneGame> game_scene =
		std::make_shared<SceneGame>();

	unsigned int splash_screenID = scene_state_machine.Add(splash_screen);
	unsigned int game_sceneID = scene_state_machine.Add(game_scene);

	splash_screen->SetSwitchToScene(game_sceneID);

	scene_state_machine.SwitchTo(splash_screenID);
}

void Game::Update() {
	scene_state_machine.Update(time_step);
}

void Game::LateUpdate() {
	scene_state_machine.LateUpdate(time_step);
}

void Game::Draw() {
	scene_state_machine.Draw(window);
}

void Game::updateTimeStep() {
	time_step = clock.getTimeStep();
}

void Game::captureInput() {
	scene_state_machine.ProcessInput();
	//input.update();
}

#endif // !GAME_HPP
