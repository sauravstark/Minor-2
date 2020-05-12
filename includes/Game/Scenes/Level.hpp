#ifndef SCENE_GAME_HPP
#define SCENE_GAME_HPP

#include "../../GameEngine/Scene.hpp"
#include "../../GameEngine/Input.hpp"
#include "..//..//GameEngine/GameObject.hpp"
#include "..//..//GameEngine/PredefinedComponents/KeyboardMovement.hpp"
#include "..//..//GameEngine/PredefinedComponents/Texture.hpp"

#include <cstdlib>

#define TAU 6.2832
struct Tex { vec<2> x; vec<2> y; };

class SceneGame : public Scene
{
public:
	void onCreate() override;
	void onDestroy() override;
	void captureInput() override;
	void update(float time_step) override;
	void lateUpdate(float time_step) override;
private:
	std::shared_ptr<GameObject> player;
	std::vector<Object> tiles;
	std::vector<Object> enemies;
	Input* input;
	float current_seconds;
};

void SceneGame::onCreate() {
	input = new Input();

	player = std::make_shared<GameObject>();
	auto sprite = player->addComponent<Texture>();
	sprite->set(0);
	sprite->setSprite({ 7.0f / 16.0f, 10.0f / 16.0f, 8.0f / 16.0f, 11.0f / 16.0f });

	current_seconds = 0.0f;
	const unsigned int count = 2;
	const unsigned int row_count = 9 * count;
	const unsigned int col_count = 16 * count;
	const float l = 2.0f / col_count;
	const float b = 2.0f / row_count;

	const float lb_x = -1.0f + l / 2;
	const float lb_y = -1.0f + b / 2;
	
	Tex brk11 = { { 10.0f / 16, 4.0f / 8 }, { 11.0f / 16, 5.0f / 8 } };
	Tex brk12 = { { 8.0f / 16, 5.0f / 8 }, { 9.0f / 16, 6.0f / 8 } };
	Tex brk13 = { { 1.0f / 16, 4.0f / 8 }, { 2.0f / 16, 5.0f / 8 } };
	Tex brk21 = { { 0.0f / 16, 5.0f / 8 }, { 1.0f / 16, 6.0f / 8 } };
	Tex brk22 = { { 1.0f / 16, 5.0f / 8 }, { 2.0f / 16, 6.0f / 8 } };
	Tex brk23 = { { 2.0f / 16, 5.0f / 8 }, { 3.0f / 16, 6.0f / 8 } };
	Tex brk24 = { { 3.0f / 16, 5.0f / 8 }, { 4.0f / 16, 6.0f / 8 } };
	Tex brk31 = { { 4.0f / 16, 5.0f / 8 }, { 5.0f / 16, 6.0f / 8 } };
	Tex brk32 = { { 5.0f / 16, 5.0f / 8 }, { 6.0f / 16, 6.0f / 8 } };
	Tex brk33 = { { 6.0f / 16, 5.0f / 8 }, { 7.0f / 16, 6.0f / 8 } };
	Tex grs1 = { { 4.0f / 16, 4.0f / 16 }, { 5.0f / 16, 5.0f / 16 } };
	Tex grs2 = { { 5.0f / 16, 4.0f / 16 }, { 6.0f / 16, 5.0f / 16 } };
	Tex grs3 = { { 6.0f / 16, 4.0f / 16 }, { 7.0f / 16, 5.0f / 16 } };
	Tex grs4 = { { 7.0f / 16, 4.0f / 16 }, { 8.0f / 16, 5.0f / 16 } };
	Tex grs5 = { { 8.0f / 16, 4.0f / 16 }, { 9.0f / 16, 5.0f / 16 } };
	Tex grs6 = { { 9.0f / 16, 4.0f / 16 }, { 10.0f / 16, 5.0f / 16 } };
	Tex ene1[3] = {
		{ { 0.0f / 16, 15.0f / 16 }, { 1.0f / 16, 16.0f / 16 } },
		{ { 1.0f / 16, 15.0f / 16 }, { 2.0f / 16, 16.0f / 16 } },
		{ { 2.0f / 16, 15.0f / 16 }, { 3.0f / 16, 16.0f / 16 } }
	};
	Tex ene2[3] = {
		{ { 0.0f / 16, 14.0f / 16 }, { 1.0f / 16, 15.0f / 16 } },
		{ { 1.0f / 16, 14.0f / 16 }, { 2.0f / 16, 15.0f / 16 } },
		{ { 2.0f / 16, 14.0f / 16 }, { 3.0f / 16, 15.0f / 16 } }
	};
	Tex ene3[3] = {
		{ { 0.0f / 16, 12.0f / 16 }, { 1.0f / 16, 13.0f / 16 } },
		{ { 1.0f / 16, 12.0f / 16 }, { 2.0f / 16, 13.0f / 16 } },
		{ { 2.0f / 16, 12.0f / 16 }, { 3.0f / 16, 13.0f / 16 } }
	};
	Tex ene4[3] = {
		{ { 0.0f / 16, 10.0f / 16 }, { 1.0f / 16, 11.0f / 16 } },
		{ { 1.0f / 16, 10.0f / 16 }, { 2.0f / 16, 11.0f / 16 } },
		{ { 2.0f / 16, 10.0f / 16 }, { 3.0f / 16, 11.0f / 16 } }
	};

	Object tile;
	tile.setScale({ l, b });
	//col 0
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x, lb_y + b * 0}));
	tiles.push_back(tile.setTexture(1, brk12.x, brk12.y).setPosition({ lb_x, lb_y + b * 1}));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x, lb_y + b * 2}));
	tiles.push_back(tile.setTexture(2, { 4.0f / 16, 4.0f / 16 }, { 5.0f / 16, 5.0f / 16 }).setPosition({ lb_x, lb_y + b * 3}));
	//col 1
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 1, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 1, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk23.x, brk23.y).setPosition({ lb_x + l * 1, lb_y + b * 2 }));
	//col 1.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 1.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk21.x, brk21.y).setPosition({ lb_x + l * 1.5f, lb_y + b * 1 }));
	//col 2.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 2.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x + l * 2.5f, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(2, grs5.x, grs5.y).setPosition({ lb_x + l * 2.5f, lb_y + b * 2 }));
	//col 3.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 3.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk23.x, brk23.y).setPosition({ lb_x + l * 3.5f, lb_y + b * 1 }));
	//col 4
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 4, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 4, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk21.x, brk21.y).setPosition({ lb_x + l * 4, lb_y + b * 2 }));
	//col 4.5
	tiles.push_back(tile.setTexture(2, grs2.x, grs2.y).setPosition({ lb_x + l * 4.5f, lb_y + b * 3 }));
	//col 5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 5, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 5, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x + l * 5, lb_y + b * 2 }));
	//col 6
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 6, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 6, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk23.x, brk23.y).setPosition({ lb_x + l * 6, lb_y + b * 2 }));
	tiles.push_back(tile.setTexture(2, grs6.x, grs6.y).setPosition({ lb_x + l * 6, lb_y + b * 3 }));
	//col 7
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 7, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x + l * 7, lb_y + b * 1 }));
	//col 8
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 8, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 8, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 8, lb_y + b * 2 }));
	tiles.push_back(tile.setTexture(1, brk24.x, brk24.y).setPosition({ lb_x + l * 8, lb_y + b * 3 }));
	tiles.push_back(tile.setTexture(2, grs3.x, grs3.y).setPosition({ lb_x + l * 8, lb_y + b * 4 }));
	//col 9
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 9, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x + l * 9, lb_y + b * 1 }));
	//col 10
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 10, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x + l * 10, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(2, grs5.x, grs5.y).setPosition({ lb_x + l * 10, lb_y + b * 2 }));
	//col 11
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 11, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk23.x, brk23.y).setPosition({ lb_x + l * 11, lb_y + b * 1 }));
	//col 11.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 11.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 11.5f, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk21.x, brk21.y).setPosition({ lb_x + l * 11.5f, lb_y + b * 2 }));
	tiles.push_back(tile.setTexture(2, grs4.x, grs4.y).setPosition({ lb_x + l * 11.5f, lb_y + b * 3 }));
	//col 12.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 12.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk13.x, brk13.y).setPosition({ lb_x + l * 12.5f, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x + l * 12.5f, lb_y + b * 2 }));
	//col 13.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 13.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 13.5f, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk23.x, brk23.y).setPosition({ lb_x + l * 13.5f, lb_y + b * 2 }));
	//col 15
	tiles.push_back(tile.setTexture(1, brk31.x, brk31.y).setPosition({ lb_x + l * 15, lb_y + b * 3 }));
	tiles.push_back(tile.setTexture(2, grs2.x, grs2.y).setPosition({ lb_x + l * 15, lb_y + b * 4 }));
	//col 16
	tiles.push_back(tile.setTexture(1, brk32.x, brk32.y).setPosition({ lb_x + l * 16, lb_y + b * 3 }));
	//col 17
	tiles.push_back(tile.setTexture(1, brk33.x, brk33.y).setPosition({ lb_x + l * 17, lb_y + b * 3 }));
	tiles.push_back(tile.setTexture(2, grs6.x, grs6.y).setPosition({ lb_x + l * 17, lb_y + b * 4 }));
	//col 17.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 17.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk21.x, brk21.y).setPosition({ lb_x + l * 17.5f, lb_y + b * 1 }));
	//col 18.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 18.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x + l * 18.5f, lb_y + b * 1 }));
	//col 19.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 19.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 19.5f, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk23.x, brk23.y).setPosition({ lb_x + l * 19.5f, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk21.x, brk21.y).setPosition({ lb_x + l * 19.5f, lb_y + b * 2 }));
	tiles.push_back(tile.setTexture(2, grs1.x, grs1.y).setPosition({ lb_x + l * 19.5f, lb_y + b * 3 }));
	//col 20.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 20.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 20.5f, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x + l * 20.5f, lb_y + b * 2 }));
	//col 21.5
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 21.5f, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 21.5f, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(1, brk23.x, brk23.y).setPosition({ lb_x + l * 21.5f, lb_y + b * 2 }));
	tiles.push_back(tile.setTexture(2, grs3.x, grs3.y).setPosition({ lb_x + l * 21.5f, lb_y + b * 3 }));
	//col 23.5
	tiles.push_back(tile.setTexture(1, brk31.x, brk31.y).setPosition({ lb_x + l * 23.5f, lb_y + b * 3 }));
	//col 24
	tiles.push_back(tile.setTexture(2, grs2.x, grs2.y).setPosition({ lb_x + l * 24, lb_y + b * 4 }));
	//col 24.5
	tiles.push_back(tile.setTexture(1, brk32.x, brk32.y).setPosition({ lb_x + l * 24.5f, lb_y + b * 3 }));
	//col 25.5
	tiles.push_back(tile.setTexture(1, brk33.x, brk33.y).setPosition({ lb_x + l * 25.5f, lb_y + b * 3 }));
	tiles.push_back(tile.setTexture(2, grs6.x, grs6.y).setPosition({ lb_x + l * 25.5f, lb_y + b * 4 }));
	//col 28
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 28, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk21.x, brk21.y).setPosition({ lb_x + l * 28, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(2, grs1.x, grs1.y).setPosition({ lb_x + l * 28, lb_y + b * 2 }));
	//col 29
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 29, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x + l * 29, lb_y + b * 1 }));
	//col 30
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 30, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk22.x, brk22.y).setPosition({ lb_x + l * 30, lb_y + b * 1 }));
	//col 31
	tiles.push_back(tile.setTexture(1, brk11.x, brk11.y).setPosition({ lb_x + l * 31, lb_y + b * 0 }));
	tiles.push_back(tile.setTexture(1, brk23.x, brk23.y).setPosition({ lb_x + l * 31, lb_y + b * 1 }));
	tiles.push_back(tile.setTexture(2, grs5.x, grs5.y).setPosition({ lb_x + l * 31, lb_y + b * 2 }));

	Object enemy;
	enemy.setScale({ l, b });
	enemies.push_back(enemy.setTexture(2, ene4[0].x, ene4[0].y).setPosition({ lb_x + l * 3, lb_y + b * 2 }));
	enemies.push_back(enemy.setTexture(2, ene1[0].x, ene1[0].y).setPosition({ lb_x + l * 7, lb_y + b * 4.5f }));
	enemies.push_back(enemy.setTexture(2, ene3[0].x, ene3[0].y).setPosition({ lb_x + l * 9, lb_y + b * 2 }));
	enemies.push_back(enemy.setTexture(2, ene2[0].x, ene2[0].y).setPosition({ lb_x + l * 12.5f, lb_y + b * 4.5f }));
	enemies.push_back(enemy.setTexture(2, ene4[0].x, ene4[0].y).setPosition({ lb_x + l * 15, lb_y + b * 4 }));
	enemies.push_back(enemy.setTexture(2, ene3[0].x, ene3[0].y).setPosition({ lb_x + l * 20.5f, lb_y + b * 3 }));
	enemies.push_back(enemy.setTexture(2, ene4[0].x, ene4[0].y).setPosition({ lb_x + l * 23.5f, lb_y + b * 4 }));
	enemies.push_back(enemy.setTexture(2, ene1[0].x, ene1[0].y).setPosition({ lb_x + l * 27, lb_y + b * 3.5f }));
	enemies.push_back(enemy.setTexture(2, ene4[0].x, ene4[0].y).setPosition({ lb_x + l * 28.5f, lb_y + b * 2 }));
	enemies.push_back(enemy.setTexture(2, ene3[0].x, ene3[0].y).setPosition({ lb_x + l * 29.5f, lb_y + b * 2 }));
	enemies.push_back(enemy.setTexture(2, ene2[0].x, ene2[0].y).setPosition({ lb_x + l * 29.5f, lb_y + b * 4.5f }));

	for (auto tile : tiles) {
		std::tuple<Vertex, Vertex, Vertex, Vertex> v2 = tile.getVertices();
		vertices.push_back(std::get<0>(v2));
		vertices.push_back(std::get<1>(v2));
		vertices.push_back(std::get<2>(v2));
		vertices.push_back(std::get<3>(v2));
	}

	for (auto enemy : enemies) {
		std::tuple<Vertex, Vertex, Vertex, Vertex> v2 = enemy.getVertices();
		vertices.push_back(std::get<0>(v2));
		vertices.push_back(std::get<1>(v2));
		vertices.push_back(std::get<2>(v2));
		vertices.push_back(std::get<3>(v2));
	}

	vertices.push_back(Vertex());
	vertices.push_back(Vertex());
	vertices.push_back(Vertex());
	vertices.push_back(Vertex());
}

void SceneGame::onDestroy() {

}

void SceneGame::captureInput() {
	input->updateInput();
}

void SceneGame::update(float time_step) {
	const unsigned int count = 2;
	const unsigned int row_count = 9 * count;
	const unsigned int col_count = 16 * count;
	const float l = 2.0f / col_count;
	const float b = 2.0f / row_count;

	const float lb_x = -1.0f + l / 2;
	const float lb_y = -1.0f + b / 2;

	Tex ene1[3] = {
		{ { 0.0f / 16, 15.0f / 16 }, { 1.0f / 16, 16.0f / 16 } },
		{ { 1.0f / 16, 15.0f / 16 }, { 2.0f / 16, 16.0f / 16 } },
		{ { 2.0f / 16, 15.0f / 16 }, { 3.0f / 16, 16.0f / 16 } }
	};
	Tex ene2[3] = {
		{ { 0.0f / 16, 14.0f / 16 }, { 1.0f / 16, 15.0f / 16 } },
		{ { 1.0f / 16, 14.0f / 16 }, { 2.0f / 16, 15.0f / 16 } },
		{ { 2.0f / 16, 14.0f / 16 }, { 3.0f / 16, 15.0f / 16 } }
	};
	Tex ene3[3] = {
		{ { 0.0f / 16, 12.0f / 16 }, { 1.0f / 16, 13.0f / 16 } },
		{ { 1.0f / 16, 12.0f / 16 }, { 2.0f / 16, 13.0f / 16 } },
		{ { 2.0f / 16, 12.0f / 16 }, { 3.0f / 16, 13.0f / 16 } }
	};
	Tex ene4[3] = {
		{ { 0.0f / 16, 10.0f / 16 }, { 1.0f / 16, 11.0f / 16 } },
		{ { 1.0f / 16, 10.0f / 16 }, { 2.0f / 16, 11.0f / 16 } },
		{ { 2.0f / 16, 10.0f / 16 }, { 3.0f / 16, 11.0f / 16 } }
	};

	current_seconds += time_step;
	int slot = int(floor(current_seconds / 0.25f)) % 4;
	int stage;
	if (slot < 2) {
		stage = slot;
	} else {
		stage = 4 - slot;
	}
	float time_elapsed = current_seconds;
	auto disp = [&, time_elapsed](float phase) {
		float angle = time_elapsed * TAU / 12 + phase * TAU / 6;
		return (sin(angle) + sin(3 * angle) + sin(5 * angle)) / 2.2308f;
	};
	enemies[ 0].setTexture(2, ene4[stage].x, ene4[stage].y).setPosition({ lb_x + l * (2.5f + 1 * disp(0)), lb_y + b * 2 });
	enemies[ 1].setTexture(2, ene1[stage].x, ene1[stage].y).setPosition({ lb_x + l * 7, lb_y + b * (4.5f - 2 * disp(1)) });
	enemies[ 2].setTexture(2, ene3[stage].x, ene3[stage].y).setPosition({ lb_x + l * (10 + 1 * disp(2)), lb_y + b * 2 });
	enemies[ 3].setTexture(2, ene2[stage].x, ene2[stage].y).setPosition({ lb_x + l * (12.5f - 2 * disp(3)), lb_y + b * 3.5f });
	enemies[ 4].setTexture(2, ene4[stage].x, ene4[stage].y).setPosition({ lb_x + l * (16 + 1 * disp(4)), lb_y + b * 4 });
	enemies[ 5].setTexture(2, ene3[stage].x, ene3[stage].y).setPosition({ lb_x + l * (20.5f + 1 * disp(5)), lb_y + b * 3 });
	enemies[ 6].setTexture(2, ene4[stage].x, ene4[stage].y).setPosition({ lb_x + l * (24.5f - 1 * disp(6)), lb_y + b * 4 });
	enemies[ 7].setTexture(2, ene1[stage].x, ene1[stage].y).setPosition({ lb_x + l * 27, lb_y + b * (3.5f + 2 * disp(7)) });
	enemies[ 8].setTexture(2, ene4[stage].x, ene4[stage].y).setPosition({ lb_x + l * (29 + 1 * disp(8)), lb_y + b * 2 });
	enemies[ 9].setTexture(2, ene3[stage].x, ene3[stage].y).setPosition({ lb_x + l * (30 - 1 * disp(9)), lb_y + b * 2 });
	enemies[10].setTexture(2, ene2[stage].x, ene2[stage].y).setPosition({ lb_x + l * (29.5f - 2 * disp(10)), lb_y + b * 4.5f });

	int index = tiles.size();
	for (auto enemy : enemies) {
		std::tuple<Vertex, Vertex, Vertex, Vertex> v2 = enemy.getVertices();
		vertices[index * 4 + 0] = std::get<0>(v2);
		vertices[index * 4 + 1] = std::get<1>(v2);
		vertices[index * 4 + 2] = std::get<2>(v2);
		vertices[index * 4 + 3] = std::get<3>(v2);
		index++;
	}

	float x_move = 0.0f, y_move = 0.0f;
	float move_speed = 0.1f;

	if (input->isKeyPressed(Input::Key::LEFT) && !input->isKeyPressed(Input::Key::RIGHT))
		x_move = -move_speed;
	else if (input->isKeyPressed(Input::Key::RIGHT) && !input->isKeyPressed(Input::Key::LEFT))
		x_move = move_speed;

	if (input->isKeyPressed(Input::Key::DOWN) && !input->isKeyPressed(Input::Key::UP))
		y_move = -move_speed;
	else if (input->isKeyPressed(Input::Key::UP) && !input->isKeyPressed(Input::Key::DOWN))
		y_move = move_speed;

	vec<2> frame_move;

	if (x_move != 0 && y_move != 0)
		frame_move = { x_move * time_step / 1.414f, y_move * time_step / 1.414f };
	else
		frame_move = { x_move * time_step, y_move * time_step };

	player->transform->move(frame_move);
}

inline void SceneGame::lateUpdate(float time_step) {
	const unsigned int count = 2;
	const unsigned int row_count = 9 * count;
	const unsigned int col_count = 16 * count;
	const float l = 2.0f / col_count;
	const float b = 2.0f / row_count;

	vec<2> pos = player->transform->getPosition();
	auto texture = player->getComponent<Texture>();
	vec<4> col = texture->getColor();
	vec<4> sprite = texture->getSprite();
	float texID = texture->getTextureID();

	std::cout << pos[0] << pos[1];

	float pos_x = pos[0], pos_y = pos[1];
	vec<3> pos1 = { pos_x - l / 2, pos_y - b / 2, 1.0f };
	vec<3> pos2 = { pos_x + l / 2, pos_y - b / 2, 1.0f };
	vec<3> pos3 = { pos_x - l / 2, pos_y + b / 2, 1.0f };
	vec<3> pos4 = { pos_x + l / 2, pos_y + b / 2, 1.0f };

	vec<3> spr1 = { sprite[0], sprite[1], texID };
	vec<3> spr2 = { sprite[2], sprite[1], texID };
	vec<3> spr3 = { sprite[0], sprite[3], texID };
	vec<3> spr4 = { sprite[2], sprite[3], texID };
	
	int index = vertices.size();

	vertices[index - 4] = { pos1, col, spr1 };
	vertices[index - 3] = { pos2, col, spr2 };
	vertices[index - 2] = { pos3, col, spr3 };
	vertices[index - 1] = { pos4, col, spr4 };
}

#endif // !SCENE_GAME_HPP
