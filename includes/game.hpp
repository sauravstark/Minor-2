#ifndef GAME_HPP
#define GAME_HPP

#include "window.hpp"
#include "vertex.hpp"
#include <vector>

class Game {
private:
	Window window;
	std::vector<Vertex> vertices;
public:
	Game();
	void Update();
	void LateUpdate();
	void Draw();
};

Game::Game() {
	float l = 2.0f / 16;
	float b = 2.0f / 9;
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 9; ++j) {
			float x = i * l + l / 2 - 1.0f;
			float y = j * b + b / 2 - 1.0f;

			Vertex v = { { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 1.0f } };
			if ((i + j) % 2 == 0)
				v.col[1] = 1.0f;
			else
				v.col[2] = 1.0f;

			v.pos[0] = x - l / 2;
			v.pos[1] = y - b / 2;
			vertices.push_back(v);

			v.pos[0] = x + l / 2;
			v.pos[1] = y - b / 2;
			vertices.push_back(v);

			v.pos[0] = x - l / 2;
			v.pos[1] = y + b / 2;
			vertices.push_back(v);

			v.pos[0] = x + l / 2;
			v.pos[1] = y + b / 2;
			vertices.push_back(v);
		}
	}
	/*
	vertices.push_back({ -0.75f, -0.75f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f });
	vertices.push_back({ -0.25f, -0.75f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f });
	vertices.push_back({ -0.75f, -0.25f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f });
	vertices.push_back({ -0.25f, -0.25f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f });

	vertices.push_back({  0.75f, -0.75f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f });
	vertices.push_back({  0.25f, -0.75f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f });
	vertices.push_back({  0.75f, -0.25f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f });
	vertices.push_back({  0.25f, -0.25f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f });
	
	vertices.push_back({ -0.75f,  0.75f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f });
	vertices.push_back({ -0.25f,  0.75f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f });
	vertices.push_back({ -0.75f,  0.25f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f });
	vertices.push_back({ -0.25f,  0.25f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f });

	vertices.push_back({  0.75f,  0.75f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f });
	vertices.push_back({  0.25f,  0.75f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f });
	vertices.push_back({  0.75f,  0.25f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f });
	vertices.push_back({  0.25f,  0.25f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f });
	*/
}

void Game::Update() {

}

void Game::LateUpdate() {
	
}

void Game::Draw() {	
	window.draw(vertices);
}

#endif // !GAME_HPP
