#ifndef SCENE_GAME_HPP
#define SCENE_GAME_HPP

#include "..//..//GameEngine/Scene.hpp"
#include "..//..//GameEngine/Input.hpp"
#include "..//..//GameEngine/GameObject.hpp"
#include "..//..//GameEngine/ObjectCollection.hpp"
#include "..//..//GameEngine/PredefinedComponents/Texture.hpp"
#include "..//..//GameEngine/PredefinedComponents/Animation.hpp"
#include "..//..///GameEngine/PredefinedComponents/Collider.hpp"
#include "..//..//Datatypes/Rect.hpp"
#include "..//Sprites/SpriteSheet.hpp"

#include <vector>

class SceneGame : public Scene {
public:
	void onCreate() override;
	void onDestroy() override;
	void captureInput() override;
	void update(float time_step) override;
private:
	Input input;
	std::shared_ptr<GameObject> player;
	std::shared_ptr<GameObject> background;
	std::vector<std::shared_ptr<GameObject>> tiles;
	std::vector<float> tile_heights;


	void createTile(unsigned x, unsigned y, SubSprite type);
	void updatePlayer(float time_step);
	void updateEnemies(float time_step);

	float box_size = 50.0f;
	float y_speed = 0.0f;
	bool grounded = false;
};

void SceneGame::onCreate() {

	//Background
	{
		
		background = createObject();
		
		auto transform = background->getComponent<Transform>();
		transform->setScale(1600.0f, 900.0f);
		
		auto texture = background->addComponent<Texture>();
		texture->set(2);
		texture->setSprite({0.0f, 0.5f, 0.5f, 1.0f});
	}
	//tiles
	{
		createTile(0, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(0, 1, SpriteSheet::Tile::Brown::centre2);
		createTile(0, 2, SpriteSheet::Tile::Brown::regular_middle);
		tile_heights.push_back(3);

		createTile(1, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(1, 1, SpriteSheet::Tile::Brown::centre1);
		createTile(1, 2, SpriteSheet::Tile::Brown::regular_right);
		tile_heights.push_back(3);

		createTile(2, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(2, 1, SpriteSheet::Tile::Brown::regular_left);
		tile_heights.push_back(2);

		createTile(3, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(3, 1, SpriteSheet::Tile::Brown::regular_right);
		tile_heights.push_back(2);

		createTile(4, 0, SpriteSheet::Tile::Brown::centre3);
		createTile(4, 1, SpriteSheet::Tile::Brown::centre1);
		createTile(4, 2, SpriteSheet::Tile::Brown::regular_left);
		tile_heights.push_back(3);

		createTile(5, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(5, 1, SpriteSheet::Tile::Brown::centre1);
		createTile(5, 2, SpriteSheet::Tile::Brown::regular_middle);
		tile_heights.push_back(3);

		createTile(6, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(6, 1, SpriteSheet::Tile::Brown::centre2);
		createTile(6, 2, SpriteSheet::Tile::Brown::regular_right);
		tile_heights.push_back(3);

		createTile(7, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(7, 1, SpriteSheet::Tile::Brown::regular_middle);
		tile_heights.push_back(2);

		createTile(8, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(8, 1, SpriteSheet::Tile::Brown::centre1);
		createTile(8, 2, SpriteSheet::Tile::Brown::centre1);
		createTile(8, 3, SpriteSheet::Tile::Brown::regular_solo);
		tile_heights.push_back(4);

		createTile(9, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(9, 1, SpriteSheet::Tile::Brown::regular_middle);
		tile_heights.push_back(2);

		createTile(10, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(10, 1, SpriteSheet::Tile::Brown::centre2);
		createTile(10, 2, SpriteSheet::Tile::Brown::regular_solo);
		tile_heights.push_back(3);

		createTile(11, 0, SpriteSheet::Tile::Brown::regular_middle);
		tile_heights.push_back(1);

		createTile(12, 0, SpriteSheet::Tile::Brown::regular_right);
		tile_heights.push_back(1);

		tile_heights.push_back(-1);

		createTile(14, 0, SpriteSheet::Tile::Brown::regular_left);
		tile_heights.push_back(1);

		createTile(15, 0, SpriteSheet::Tile::Brown::regular_right);
		tile_heights.push_back(1);

		tile_heights.push_back(-1);

		createTile(17, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(17, 1, SpriteSheet::Tile::Brown::regular_left);
		tile_heights.push_back(2);

		createTile(18, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(18, 1, SpriteSheet::Tile::Brown::regular_middle);
		tile_heights.push_back(2);

		createTile(19, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(19, 1, SpriteSheet::Tile::Brown::centre1);
		createTile(19, 2, SpriteSheet::Tile::Brown::regular_left);
		tile_heights.push_back(3);

		createTile(20, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(20, 1, SpriteSheet::Tile::Brown::centre1);
		createTile(20, 2, SpriteSheet::Tile::Brown::regular_middle);
		tile_heights.push_back(3);

		createTile(21, 0, SpriteSheet::Tile::Brown::centre3);
		createTile(21, 1, SpriteSheet::Tile::Brown::centre1);
		createTile(21, 2, SpriteSheet::Tile::Brown::centre1);
		createTile(21, 3, SpriteSheet::Tile::Brown::regular_left);
		tile_heights.push_back(4);

		createTile(22, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(22, 1, SpriteSheet::Tile::Brown::centre2);
		createTile(22, 2, SpriteSheet::Tile::Brown::centre1);
		createTile(22, 3, SpriteSheet::Tile::Brown::regular_middle);
		tile_heights.push_back(4);

		createTile(23, 0, SpriteSheet::Tile::Brown::centre1);
		createTile(23, 1, SpriteSheet::Tile::Brown::centre1);
		createTile(23, 2, SpriteSheet::Tile::Brown::centre1);
		createTile(23, 3, SpriteSheet::Tile::Brown::regular_right);
		tile_heights.push_back(4);

		createTile(24, 0, SpriteSheet::Tile::Brown::regular_left);
		tile_heights.push_back(1);

		createTile(25, 0, SpriteSheet::Tile::Brown::regular_middle);
		tile_heights.push_back(1);

		createTile(26, 0, SpriteSheet::Tile::Brown::regular_right);
		tile_heights.push_back(1);

		tile_heights.push_back(-1);

		createTile(28, 0, SpriteSheet::Tile::Brown::regular_left);
		tile_heights.push_back(1);

		createTile(29, 0, SpriteSheet::Tile::Brown::regular_right);
		tile_heights.push_back(1);

		tile_heights.push_back(-1);
		
		createTile(31, 1, SpriteSheet::Tile::Brown::floating_left);
		tile_heights.push_back(2);
	}
	//enemy
	{
		//spawn_enemy();
	}
	//player
	{
		player = createObject();

		auto transform = player->getComponent<Transform>();
		transform->setScale(box_size, box_size);
		transform->setX(-15.5f * box_size);

		auto texture = player->addComponent<Texture>();
		texture->set(0);

		auto animation = player->addComponent<Animation>();

		auto idle = std::make_shared<FrameSet>(1, Repeat::ALTERNATE);
		idle->setFrameData(0, Frame(SpriteSheet::Player::Grey::stand));

		auto move = std::make_shared<FrameSet>(3, Repeat::ALTERNATE);
		move->setFrameData(0, Frame(SpriteSheet::Player::Grey::walk_1));
		move->setFrameData(1, Frame(SpriteSheet::Player::Grey::walk_2));
		move->setFrameData(2, Frame(SpriteSheet::Player::Grey::walk_3));

		animation->addAnimation("idle", idle);
		animation->addAnimation("move", move);
		animation->setAnimation("idle");

		auto collider = player->addComponent<Collider>();
	}
}

void SceneGame::onDestroy() {

}

void SceneGame::captureInput() {
	input.updateInput();
}

void SceneGame::update(float time_step) {
	updatePlayer(time_step);
	updateEnemies(time_step);
}

void SceneGame::createTile(unsigned x, unsigned y, SubSprite type) {
	float s_width = 1600.0f / box_size;
	float s_height = 900.0f / box_size;
	float str_x = -(s_width / 2 - 0.5) * box_size;
	float str_y = -(s_height / 2 - 0.5) * box_size;

	auto tile = createObject();
	
	auto transform = tile->addComponent<Transform>();
	transform->setPos(str_x + box_size * x, str_y + box_size * y);
	transform->setScale(box_size, box_size);

	auto texture = tile->addComponent<Texture>();
	texture->set(1);
	texture->setSprite(type);
}

void SceneGame::updatePlayer(float time_step) {
	auto transform = player->getComponent<Transform>();
	
	float x_mov = 0.0f;
	if (input.isKeyPressed(Input::Key::RIGHT))
		x_mov += 200.0f * time_step;
	if (input.isKeyPressed(Input::Key::LEFT))
		x_mov -= 200.0f * time_step;
	transform->moveX(x_mov);

	int i = (transform->getPosition()[0] + 800.0f) / box_size;
	float tile_height = 0.0f;
	if (i >= 0 && i <= 31)
		tile_height = tile_heights[i] * box_size + box_size * 0.5f - 450.0f;
	
	float jump_height = 50.0f;
	float jump_time = 0.5;

	float acc = (-2 * jump_height) / (jump_time * jump_time / 4);
	float u_y = -acc * jump_time / 2;

	if (grounded) {
		if ( input.isKeyPressed(Input::Key::UP)) {
			grounded = false;
			y_speed = u_y;
		} else if (transform->getPosition()[1] < tile_height) {
			grounded = false;
			y_speed = 0.0f;
		} else {
			y_speed = 0.0f;
		}
	} else {
		y_speed += acc * time_step;
		y_speed = std::max(-u_y, y_speed);
	}

	float prev_y = transform->getPosition()[1];
	float next_y = prev_y + y_speed * time_step;

	if (grounded && next_y > tile_height) {
		grounded = false;
	} else if (!grounded && next_y < tile_height && prev_y > tile_height) {
		grounded = true;
		next_y = tile_height;
	}
	transform->setY(next_y);

	if (transform->getPosition()[1] < -450.0f ||transform->getPosition()[0] < -800.0f || transform->getPosition()[0] > 800.0f ) {
		transform->setPos(-15.5f * box_size, -5.0f * box_size);
		grounded = false;
		y_speed = 0.0f;
	}

	if (grounded && x_mov != 0.0f)
		player->getComponent<Animation>()->setAnimation("move");
	else
		player->getComponent<Animation>()->setAnimation("idle");
}

void SceneGame::updateEnemies(float time_step) {

}

#endif // !SCENE_GAME_HPP
