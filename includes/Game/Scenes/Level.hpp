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
#include <cstdlib>

class SceneGame : public Scene {
public:
	void onCreate() override;
	void onDestroy() override;
	void captureInput() override;
	void update(float time_step) override;
private:
	Input input;
	std::shared_ptr<GameObject> player;
	std::vector<std::shared_ptr<GameObject>> tiles;
	std::shared_ptr<GameObject> background;
	const float box_size = 50.0f;
	float y_speed = 0.0f;
	bool isGrounded = false;
	//collider type 1: middle, type 2: left_half, type 3: right_half
	std::shared_ptr<GameObject> placeTile(vec<2> pos, const SubSprite type, int collider_type);
};

void SceneGame::onCreate() {

	//Background
	{
		
		background = createObject();
		
		auto transform = background->getComponent<Transform>();
		transform->setScale(1600.0f, 900.0f);
		
		auto texture = background->addComponent<Texture>();
		texture->set(2);
		texture->setSprite(SpriteSheet::Background::Blue);
	}
	//Tiles
	{
		tiles.push_back(placeTile({ 0.0f, 0.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 0.0f, 1.0f }, SpriteSheet::Tile::Brown::centre2, 0));
		tiles.push_back(placeTile({ 0.0f, 2.0f }, SpriteSheet::Tile::Brown::regular_middle, 1));
																		  
		tiles.push_back(placeTile({ 1.0f, 0.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 1.0f, 1.0f }, SpriteSheet::Tile::Brown::baseless_half_left, 2));
		tiles.push_back(placeTile({ 1.0f, 2.0f }, SpriteSheet::Tile::Brown::regular_right, 1));
																		  
		tiles.push_back(placeTile({ 2.0f, 0.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 2.0f, 1.0f }, SpriteSheet::Tile::Brown::regular_middle, 1));
																		  
		tiles.push_back(placeTile({ 3.0f, 0.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 3.0f, 1.0f }, SpriteSheet::Tile::Brown::regular_middle, 1));
																		  
		tiles.push_back(placeTile({ 4.0f, 0.0f }, SpriteSheet::Tile::Brown::centre3, 0));
		tiles.push_back(placeTile({ 4.0f, 1.0f }, SpriteSheet::Tile::Brown::baseless_half_right, 3));
		tiles.push_back(placeTile({ 4.0f, 2.0f }, SpriteSheet::Tile::Brown::regular_left, 1));
																		  
		tiles.push_back(placeTile({ 5.0f, 0.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 5.0f, 1.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 5.0f, 2.0f }, SpriteSheet::Tile::Brown::regular_middle, 1));
																		  
		tiles.push_back(placeTile({ 6.0f, 0.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 6.0f, 1.0f }, SpriteSheet::Tile::Brown::centre2, 0));
		tiles.push_back(placeTile({ 6.0f, 2.0f }, SpriteSheet::Tile::Brown::regular_right, 1));
																		  
		tiles.push_back(placeTile({ 7.0f, 0.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 7.0f, 1.0f }, SpriteSheet::Tile::Brown::regular_middle, 1));
																		  
		tiles.push_back(placeTile({ 8.0f, 0.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 8.0f, 1.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 8.0f, 2.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 8.0f, 3.0f }, SpriteSheet::Tile::Brown::regular_solo, 1));
																		  
		tiles.push_back(placeTile({ 9.0f, 0.0f }, SpriteSheet::Tile::Brown::centre1, 0));
		tiles.push_back(placeTile({ 9.0f, 1.0f }, SpriteSheet::Tile::Brown::regular_middle, 1));
	}
	//player
	{
		player = createObject();

		auto transform = player->getComponent<Transform>();
		transform->setPos(-800.0f + box_size, 0.0f);
		transform->setScale(box_size, box_size);

		auto texture = player->addComponent<Texture>();
		texture->set(0);

		auto collider = player->addComponent<Collider>();
		collider->setSize({ 0.0f, 0.0f });
		collider->setPosition({ 0.0f, -0.5f });

		auto animation = player->addComponent<Animation>();
		auto walk_animation = std::make_shared<FrameSet>(5, Repeat::ALTERNATE);
		walk_animation->setFrameData(0, Frame(SpriteSheet::Player::Blue::walk_1, 0.0625f));
		walk_animation->setFrameData(1, Frame(SpriteSheet::Player::Blue::walk_2, 0.0625f));
		walk_animation->setFrameData(2, Frame(SpriteSheet::Player::Blue::walk_3, 0.0625f));
		walk_animation->setFrameData(3, Frame(SpriteSheet::Player::Blue::walk_4, 0.0625f));
		walk_animation->setFrameData(4, Frame(SpriteSheet::Player::Blue::walk_5, 0.0625f));
		animation->addAnimation("MOVE", walk_animation);

		auto idle_animation = std::make_shared<FrameSet>(1);
		idle_animation->setFrameData(0, Frame(SpriteSheet::Player::Blue::stand));
		animation->addAnimation("IDLE", idle_animation);
	}
}

void SceneGame::onDestroy() {

}

void SceneGame::captureInput() {
	input.updateInput();
}

void SceneGame::update(float time_step) {
	auto collider = player->getComponent<Collider>();
	isGrounded = false;
	for (auto tile : tiles) {
		if (tile->getComponent<Collider>()->collides(collider)) {
			isGrounded = true;
			break;
		}
	}

	auto transform = player->getComponent<Transform>();
	float speed = 100.0f;
	float x_move = 0.0f, y_move = 0.0f;
	if (input.isKeyPressed(Input::Key::RIGHT) && !input.isKeyPressed(Input::Key::LEFT)) {
		x_move = speed * time_step;
	} else if (input.isKeyPressed(Input::Key::LEFT) && !input.isKeyPressed(Input::Key::RIGHT)) {
		x_move = -speed * time_step;
	}
	
	if (isGrounded) {
		if (input.isKeyPressed(Input::Key::UP))
			y_speed = 200.0f;
		else
			y_speed = 0.0f;
	} else {
		if (y_speed > -400.0f)
			y_speed -= 50.0f * time_step;
	}

	y_move = y_speed * time_step;

	transform->move(x_move, y_move);
	
	auto animation = player->getComponent<Animation>();
	if (x_move != 0.0f) {
		animation->setAnimation("MOVE");
		if (x_move > 0.0f) {
			transform->flipY(false);
		} else {
			transform->flipY(true);
		}
	} else {
		animation->setAnimation("IDLE");
	}
	
}

inline std::shared_ptr<GameObject> SceneGame::placeTile(vec<2> pos, const SubSprite type, int  collider_type) {
	const float horizontal_tile_count = 1600.0f / box_size;
	const float vertical_tile_count = 900.0f / box_size;
	const float start_x = (-horizontal_tile_count * 0.5f + 0.5) * box_size;
	const float start_y = (-vertical_tile_count * 0.5f + 0.5) * box_size;

	auto tile = createObject();

	auto transform = tile->getComponent<Transform>();
	transform->setScale(box_size, box_size);
	transform->setPos(pos * box_size + vec<2>(start_x, start_y));

	auto texture = tile->addComponent<Texture>();
	texture->set(1);
	texture->setSprite(type);

	using namespace SpriteSheet::Tile;

	if (collider_type == 1) {
		auto collider = tile->addComponent<Collider>();
		collider->setSize({ 1.0f, 0.2f });
		collider->setPosition({ 0.0f, 0.4f });
	} else if (collider_type == 2){
		auto collider = tile->addComponent<Collider>();
		collider->setSize({ 0.5f, 0.2f });
		collider->setPosition({0.25f, 0.4f });
	} else if (collider_type == 3) {		
		auto collider = tile->addComponent<Collider>();
		collider->setSize({ 0.5f, 0.2f });
		collider->setPosition({-0.25f, 0.4f });
	}

	return tile;
}

#endif // !SCENE_GAME_HPP
