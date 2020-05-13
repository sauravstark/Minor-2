#ifndef GAME_HPP
#define GAME_HPP

#include "../GameEngine/Window.hpp"
#include "../Datatypes/Vertex.hpp"
//#include "../Datatypes/Object.hpp"
#include "../GameEngine/Clock.hpp"
//#include "input.hpp"
#include "../GameEngine/SceneStateMachine.hpp"
#include "./Scenes/SplashScreen.hpp"
#include "./Scenes/Level.hpp"
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Game {
private:
	Window window;
	Clock clock;
	//Input input;
	float time_step;
	//std::vector<Vertex> vertices;
	//Object player;
	SceneStateMachine scene_state_machine;
	//std::unordered_set<Object> objects;
	//std::unordered_map<unsigned long long int, unsigned long long int> index_map;
public:
	Game();
	void update();
	void lateUpdate();
	void draw();
	void updateTimeStep();
	void captureInput();
};

Game::Game() : time_step(0.0f){
	std::shared_ptr<SceneSplashScreen> splash_screen =
		std::make_shared<SceneSplashScreen>(scene_state_machine);
	std::shared_ptr<SceneGame> game_scene =
		std::make_shared<SceneGame>();

	unsigned int splash_screenID = scene_state_machine.addScene(splash_screen);
	unsigned int game_sceneID = scene_state_machine.addScene(game_scene);

	splash_screen->setSwitchToScene(game_sceneID);

	scene_state_machine.switchToScene(splash_screenID);
}

void Game::update() {
	scene_state_machine.update(time_step);
}

void Game::lateUpdate() {
	scene_state_machine.lateUpdate(time_step);
}

void Game::draw() {
	scene_state_machine.draw(window);
}

void Game::updateTimeStep() {
	time_step = clock.getTimeStep();
}

void Game::captureInput() {
	scene_state_machine.captureInput();
	//input.update();
}

#endif // !GAME_HPP
