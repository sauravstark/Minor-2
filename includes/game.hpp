#ifndef GAME_HPP
#define GAME_HPP

#include "renderer.hpp"

class Game {
private:
	Renderer renderer;
	
public:
	Game();
	void Update();
	void LateUpdate();
	void Draw();
};

Game::Game() {
	
}

void Game::Update() {
	renderer.update();
}

void Game::LateUpdate() {
	
}

void Game::Draw() {
	
	renderer.draw();
}

#endif // !GAME_HPP
