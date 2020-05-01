#ifndef GAME_HPP
#define GAME_HPP

#include "window.hpp"
#include "vertex.hpp"
#include "object.hpp"
#include "clock.hpp"
#include "input.hpp"
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Game {
private:
	Window window;
	Clock clock;
	Input input;
	float time_step;
	std::vector<Vertex> vertices;
	Object player;
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
	float l = 2.0f / 16;
	float b = 2.0f / 9;
	Object obj;
	obj.setScale(vec<2>(l, b));
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 9; ++j) {
			float x = i * l + l / 2 - 1.0f;
			float y = j * b + b / 2 - 1.0f;

			obj.setPosition(vec<2>(x, y));
			if ((i + j) % 2 == 0)
				obj.setColor(vec<4>(1.0f, 0.0f, 0.0f, 1.0f));
			else
				obj.setColor(vec<4>(0.0f, 0.0f, 1.0f, 1.0f));

			std::tuple<Vertex, Vertex, Vertex, Vertex> v = obj.getVertices();
			vertices.push_back(std::get<0>(v));
			vertices.push_back(std::get<1>(v));
			vertices.push_back(std::get<2>(v));
			vertices.push_back(std::get<3>(v));
		}
	}
	player.setScale(vec<2>(l, b)).setColor(vec<4>(0.0f, 0.0f, 0.0f, 1.0f)).setPosition(vec<2>(0.0f, 0.0f));
	std::tuple<Vertex, Vertex, Vertex, Vertex> v = player.getVertices();
	vertices.push_back(std::get<0>(v));
	vertices.push_back(std::get<1>(v));
	vertices.push_back(std::get<2>(v));
	vertices.push_back(std::get<3>(v));
}

void Game::Update() {
	vec<2> pos = player.getPosition();
	const float speed = 2000.0f / 1920;

	float x_mov = 0.0f, y_mov = 0.0f;
	if(input.isKeyPressed(Input::Key::Right) && !input.isKeyPressed(Input::Key::Left))
        x_mov = speed * time_step;

    if(!input.isKeyPressed(Input::Key::Right) && input.isKeyPressed(Input::Key::Left))
        x_mov = -speed * time_step;

	if(input.isKeyPressed(Input::Key::Up) && !input.isKeyPressed(Input::Key::Down))
        y_mov = speed * time_step;

    if(!input.isKeyPressed(Input::Key::Up) && input.isKeyPressed(Input::Key::Down))
        y_mov = -speed * time_step;

	if ((x_mov != 0) && (y_mov != 0)) {
		x_mov /= 1.414f;
		y_mov /= 1.414f;
	}

	player.setPosition(vec<2>(pos[0] + x_mov, pos[1] + y_mov));
	std::tuple<Vertex, Vertex, Vertex, Vertex> v = player.getVertices();
	unsigned index = vertices.size();
	vertices[index - 4] = std::get<0>(v);
	vertices[index - 3] = std::get<1>(v);
	vertices[index - 2] = std::get<2>(v);
	vertices[index - 1] = std::get<3>(v);
}

void Game::LateUpdate() {
	
}

void Game::Draw() {	
	window.draw(vertices);
}

void Game::updateTimeStep() {
	time_step = clock.getTimeStep();
}

void Game::captureInput() {
	input.update();
}

#endif // !GAME_HPP
