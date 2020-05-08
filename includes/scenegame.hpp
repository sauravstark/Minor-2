#ifndef SCENE_GAME_HPP
#define SCENE_GAME_HPP

#include "scene.hpp"
#include "input.hpp"
#include <cstdlib>

class SceneGame : public Scene
{
public:
	void OnCreate() override;
	void OnDestroy() override;
	void ProcessInput() override;
	void Update(float time_step) override;
private:
	Object player;
	Object bullet;
	Input input;
};

void SceneGame::OnCreate() {
	const unsigned int count = 2;
	const unsigned int row_count = 9 * count;
	const unsigned int col_count = 16 * count;
	const float l = 2.0f / col_count;
	const float b = 2.0f / row_count;
	
	Object back;
	back.setScale(vec<2>(2.0f, 2.0f)).setTexture(2, vec<2>(0.0f, 7.0f / 32), vec<2>(1.0f, 1.0f - 7.0f / 32));
	std::tuple<Vertex, Vertex, Vertex, Vertex> v = back.getVertices();
	vertices.push_back(std::get<0>(v));
	vertices.push_back(std::get<1>(v));
	vertices.push_back(std::get<2>(v));
	vertices.push_back(std::get<3>(v));
	player.setScale(vec<2>(l * 2, b * 2)).setTexture(0, vec<2>(2.0f / 8, 4.0f / 8), vec<2>(4.0f / 8, 6.0f / 8)).setPosition(vec<2>(0.0f, 0.0f));
	std::tuple<Vertex, Vertex, Vertex, Vertex> v1 = player.getVertices();
	vertices.push_back(std::get<0>(v1));
	vertices.push_back(std::get<1>(v1));
	vertices.push_back(std::get<2>(v1));
	vertices.push_back(std::get<3>(v1));
	
	bullet.setScale(vec<2>(l, b)).setTexture(1, vec<2>(1.0f / 8, 2.0f / 8), vec<2>(2.0f / 8, 3.0f / 8)).setPosition(vec<2>(0.5f, -0.5f));
	std::tuple<Vertex, Vertex, Vertex, Vertex> v2 = bullet.getVertices();
	vertices.push_back(std::get<0>(v2));
	vertices.push_back(std::get<1>(v2));
	vertices.push_back(std::get<2>(v2));
	vertices.push_back(std::get<3>(v2));
	
}

void SceneGame::OnDestroy() {

}

void SceneGame::ProcessInput() {
	input.update();
}

float animation_time = 0.0f;

void SceneGame::Update(float time_step) {

	const unsigned int count = 2;
	const unsigned int row_count = 9 * count;
	const unsigned int col_count = 16 * count;
	const float l = 2.0f / col_count;
	const float b = 2.0f / row_count;

	const float speed = 1000.0f / 1920;

	vec<2> pos = player.getPosition();
	float x_mov = 0.0f, y_mov = 0.0f;
	if (input.isKeyPressed(Input::Key::Right) && !input.isKeyPressed(Input::Key::Left))
		x_mov = speed * time_step;

	if (!input.isKeyPressed(Input::Key::Right) && input.isKeyPressed(Input::Key::Left))
		x_mov = -speed * time_step;

	if (input.isKeyPressed(Input::Key::Up) && !input.isKeyPressed(Input::Key::Down))
		y_mov = speed * time_step;

	if (!input.isKeyPressed(Input::Key::Up) && input.isKeyPressed(Input::Key::Down))
		y_mov = -speed * time_step;

	if ((x_mov != 0) && (y_mov != 0)) {
		x_mov /= 1.414f;
		y_mov /= 1.414f;
	}

	player.setPosition(vec<2>(pos[0] + x_mov, pos[1] + y_mov));
	pos = player.getPosition();
	std::tuple<Vertex, Vertex, Vertex, Vertex> v1 = player.getVertices();
	unsigned index = vertices.size();
	vertices[index - 8] = std::get<0>(v1);
	vertices[index - 7] = std::get<1>(v1);
	vertices[index - 6] = std::get<2>(v1);
	vertices[index - 5] = std::get<3>(v1);
	
	vec<2> e_pos = bullet.getPosition();
	float delta_x = pos[0] - e_pos[0];
	float delta_y = pos[1] - e_pos[1];
	float dir = atan2f(delta_y, delta_x);
	x_mov = speed * 0.75f * cos(dir) * time_step;
	y_mov = speed * 0.75f * sin(dir) * time_step;
	float dist = sqrtf(powf(delta_x, 2) + powf(delta_y, 2));
	if (dist > speed * 0.75f * time_step) {
		bullet.setPosition(vec<2>(e_pos[0] + x_mov, e_pos[1] + y_mov)).setRotation(vec<1>(dir - 3.14f / 2));
	} else {
		const float frame_time = 0.125f;
		float stage;
		if (animation_time < frame_time * 8) {
			stage = floorf(animation_time / frame_time);
			bullet.setPosition(player.getPosition()).setTexture(1, { stage / 8, 6.0f / 8 }, { (stage + 1) / 8, 7.0f / 8 }).setScale({ l * 4, b * 4 });
			animation_time += time_step;
		}
		else {
			stage = 0.0f;
			dir = float(rand());
			bullet.setPosition({ pos[0] + 2 * cos(dir), pos[1] + 2 * sin(dir) }).setScale({ l, b }).setTexture(1, { 1.0f / 8, 2.0f / 8 }, { 2.0f / 8, 3.0f / 8 });
			animation_time = 0.0f;
		}
	}
	std::tuple<Vertex, Vertex, Vertex, Vertex> v2 = bullet.getVertices();
	vertices[index - 4] = std::get<0>(v2);
	vertices[index - 3] = std::get<1>(v2);
	vertices[index - 2] = std::get<2>(v2);
	vertices[index - 1] = std::get<3>(v2);

}

#endif // !SCENE_GAME_HPP
