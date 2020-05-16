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

struct EStat {
	bool isActive;
	float speed;
	float attack;
	float health;
	float cooldown;
};

class SceneGame : public Scene {
public:
	void onCreate() override;
	void onDestroy() override;
	void captureInput() override;
	void update(float time_step) override;
private:
	Input input;
	float box_size = 100.0f;
	float spawn_cooldown = 0.0f;
	std::shared_ptr<GameObject> player;
	std::pair<std::shared_ptr<GameObject>, EStat> enemies[16] = { {nullptr, EStat()} };

	void updatePlayer(float time_step);
	void updateEnemies(float time_step);
	void updatePlayerBullets(float time_step);
	void updateEnemyBullets(float time_step);

	void spawnEnemy();
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
		for (unsigned i = 0; i < 16; ++i) {
			enemies[i].first = createObject();
			enemies[i].first->addComponent<Texture>()->set(0);
			enemies[i].first->addComponent<Collider>();
			enemies[i].second.isActive = false;
		}
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
	updatePlayerBullets(time_step);
	updateEnemyBullets(time_step);
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
	spawn_cooldown -= time_step;
	if (spawn_cooldown <= 0.0f) {
		spawnEnemy();
	}
	auto p_pos = player->getComponent<Transform>()->getPosition();
	for (unsigned i = 0; i < 16; ++i) {
		if (enemies[i].second.isActive) {
			auto enemy = enemies[i].first;
			auto stat = enemies[i].second;
			auto transform = enemy->getComponent<Transform>();
			auto e_pos = transform->getPosition();
			float step_length = stat.speed * time_step;
			vec<2> disp = p_pos - e_pos;
			if (step_length < sqrtf(disp[0] * disp[0] + disp[1] * disp[1])) {
				disp.normalize();
				float angle = atan2f(disp[1], disp[0]) - PI * 0.5f;
				transform->move(disp * step_length);
				transform->setRot(angle);
			}
		}
	}
}

inline void SceneGame::updatePlayerBullets(float time_step) {
}

inline void SceneGame::updateEnemyBullets(float time_step) {
}

inline void SceneGame::spawnEnemy() {
	for (unsigned i = 0; i < 16; ++i) {
		if (enemies[i].second.isActive == false) {
			enemies[i].second.isActive = true;
			auto enemy = enemies[i].first;
			auto transform = enemy->getComponent<Transform>();
			auto texture = enemy->getComponent<Texture>();
			float dir = rand();
			transform->setPos(1000 * cos(dir), 1000 * sin(dir));
			unsigned type = rand() % 5;
			switch (type)
			{
			case 0:
				texture->setSprite(SpriteSheet::Player::cargoship);
				transform->setScale(box_size * 0.5f, box_size);
				enemies[i].second.speed = 250.0f;
				break;
			case 1:
				texture->setSprite(SpriteSheet::Player::carrier);
				enemies[i].second.speed = 150.0f;
				break;
			case 2:
				texture->setSprite(SpriteSheet::Player::cruiser);
				transform->setScale(box_size * 0.5f, box_size);
				enemies[i].second.speed = 100.0f;
				break;
			case 3:
				texture->setSprite(SpriteSheet::Player::destroyer);
				enemies[i].second.speed = 200.0f;
				break;
			case 4:
				texture->setSprite(SpriteSheet::Player::shuttle);
				transform->setScale(box_size * 0.5f, box_size);
				enemies[i].second.speed = 300.0f;
				break;
			}
			break;
		}
	}
	spawn_cooldown = 5.0f;
}

#endif // !SCENE_GAME_HPP
