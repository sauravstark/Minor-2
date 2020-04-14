#ifndef GAME_HPP
#define GAME_HPP

#include "window.hpp"

class Game {
private:
	Window window;
	
public:
	Game();
	void Update();
	void LateUpdate();
	void Draw();
};

Game::Game() {
	
}

void Game::Update() {
	window.update();
}

void Game::LateUpdate() {
	
}

void Game::Draw() {
	
	window.beginDraw();
	window.draw();
	window.endDraw();
}

#endif // !GAME_HPP
