#ifndef SCENE_GAME_HPP
#define SCENE_GAME_HPP

#include "..//..//GameEngine/Input.hpp"
#include "..//..//GameEngine/PredefinedComponents/Texture.hpp"
#include "..//..//GameEngine/PredefinedComponents/Animation.hpp"
#include "..//..///GameEngine/PredefinedComponents/Collider.hpp"
#include "..//Sprites/SpriteSheet.hpp"

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

class SceneGame : public Scene {
public:
	void onCreate() override;
	void onDestroy() override;
	void captureInput() override;
	void update(float time_step) override;
private:
	Input input;
	std::shared_ptr<GameObject> player;
	float box_size = 100.0f;

	void updatePlayer(float time_step);
	void updateEnemies(float time_step);
	void updatePlayerBullets(float time_step);
	void updateEnemyBullets(float time_step);

	void spawn_enemy();
};

void SceneGame::onCreate() {

	//Background
	{
		
		auto background = createObject();
		
		auto transform = background->getComponent<Transform>();
		transform->setScale(1600.0f, 900.0f);
		
		auto texture = background->addComponent<Texture>();
		texture->set(2);
	}
	//player
	{
		player = createObject();

		auto transform = player->getComponent<Transform>();
		transform->setScale(box_size, box_size);

		auto texture = player->addComponent<Texture>();
		texture->set(0);
		texture->setSprite(SpriteSheet::Player::red_fighter5);

		auto collider = player->addComponent<Collider>();
	}
	//enemy
	{
		//spawn_enemy();
	}
}

void SceneGame::onDestroy() {

}

void SceneGame::captureInput() {
	input.updateInput();
}

void SceneGame::update(float time_step) {
	updatePlayer(time_step);
	/*
	update_enemy(time_step);
	updateEnemyBullet(time_step);
	cooldown_time -= time_step;
	if (cooldown_time <= 0.0f)
		spawn_enemy();
	*/
}

inline void SceneGame::updatePlayer(float time_step) {
	//move
	float speed = 250.0f;
	auto transform = player->getComponent<Transform>();
	float cur_dir = transform->getRotation();
	cur_dir = atan2f(sin(cur_dir), cos(cur_dir));
	cur_dir = (cur_dir < 0.0f ? 2 * PI + cur_dir : cur_dir);
	float req_dir = cur_dir;
	bool N = input.isKeyPressed(Input::Key::UP);
	bool E = input.isKeyPressed(Input::Key::RIGHT);
	bool W = input.isKeyPressed(Input::Key::LEFT);
	bool S = input.isKeyPressed(Input::Key::DOWN);

	if (N && !S && !E && !W)	req_dir = PI * 0.00f;
	else if (S && !N && !E && !W)	req_dir = PI * 1.00f;
	else if (E && !W && !N && !S)	req_dir = PI * 1.50f;
	else if (W && !E && !N && !S)	req_dir = PI * 0.50f;
	else if (N && E && !S && !W)	req_dir = PI * 1.75f;
	else if (N && W && !S && !E)	req_dir = PI * 0.25f;
	else if (S && E && !S && !W)	req_dir = PI * 1.25f;
	else if (S && W && !S && !E)	req_dir = PI * 0.25f;

	if (abs(req_dir - cur_dir) > PI * 0.5 * time_step) {
		if (abs(req_dir - cur_dir) <= PI)
			cur_dir += sgn(req_dir - cur_dir) * PI * 0.5 * time_step;
		else
			cur_dir += sgn(cur_dir - req_dir) * PI * 0.5 * time_step;
	}
	else {
		cur_dir = req_dir;
	}

	transform->setRot(cur_dir);
	transform->move(speed * cos(cur_dir + PI * 0.5f) * time_step, speed * sin(cur_dir + PI * 0.5f) * time_step);
}

inline void SceneGame::updateEnemies(float time_step) {
}

inline void SceneGame::updatePlayerBullets(float time_step) {
}

inline void SceneGame::updateEnemyBullets(float time_step) {
}

inline void SceneGame::spawn_enemy() {
}

#endif // !SCENE_GAME_HPP
