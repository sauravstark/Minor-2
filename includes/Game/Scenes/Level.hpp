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
#include <map>
#include <cstdlib>
#include <algorithm>


struct BulletStats {
	float attack;
	float speed;
};

struct EnemyStats {
	EnemyStats(int seed);
	EnemyStats(const EnemyStats& other);
	float health;
	float speed;
	float cooldown;
	float attack;
	int type;
	void resetCooldown();
};

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
	std::vector<std::pair<std::shared_ptr<GameObject>, EnemyStats>> enemies;
	std::vector<std::pair<std::shared_ptr<GameObject>, BulletStats>> e_bullets;
	std::vector<std::pair<std::shared_ptr<GameObject>, std::shared_ptr<GameObject>>> p_bullets;
	float box_size = 100.0f;
	float cooldown_time = 0.0f;

	void spawn_enemy();
	void fireEnemyBullet(std::pair<std::shared_ptr<GameObject>, EnemyStats> pair);
	void move_player(float time_step);
	void update_enemy(float time_step);
	void updateEnemyBullet(float time_step);
	void end();

	std::vector<std::shared_ptr<GameObject>> inactive_objects;
};

void SceneGame::onCreate() {

	//Background
	{
		
		background = createObject();
		
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
		//texture->setSprite(SpriteSheet::Player::red_fighter5);

		auto collider = player->addComponent<Collider>();
	}
	//enemy
	{
		spawn_enemy();
	}
}

void SceneGame::onDestroy() {

}

void SceneGame::captureInput() {
	input.updateInput();
}

void SceneGame::update(float time_step) {
	move_player(time_step);
	update_enemy(time_step);
	updateEnemyBullet(time_step);
	cooldown_time -= time_step;
	if (cooldown_time <= 0.0f)
		spawn_enemy();
}

inline void SceneGame::spawn_enemy() {
	cooldown_time = 5.0f;
	int seed = rand();
	std::shared_ptr<GameObject> new_enemy;
	if (!inactive_objects.empty()) {
		new_enemy = inactive_objects[inactive_objects.size() - 1];
		inactive_objects.pop_back();
	} else {
		new_enemy = createObject();
	}
	EnemyStats new_stat(seed);
	enemies.push_back({ new_enemy, new_stat });

	auto transform = new_enemy->getComponent<Transform>();
	transform->setScale(box_size, box_size);
	float dir = rand();
	transform->setPos(-800.0f * cosf(dir), -800.0f * sinf(dir));

	auto texture = new_enemy->addComponent<Texture>();
	texture->set(0);
	/*
	switch (seed % 5)
	{
	case 0:
		texture->setSprite(SpriteSheet::Player::cargoship);
		transform->setScale(box_size * 0.5f, box_size);
		break;
	case 1:
		texture->setSprite(SpriteSheet::Player::carrier);
		break;
	case 2:
		texture->setSprite(SpriteSheet::Player::destroyer);
		break;
	case 3:
		texture->setSprite(SpriteSheet::Player::cruiser);
		transform->setScale(box_size * 0.5f, box_size);
		break;
	case 4:
		texture->setSprite(SpriteSheet::Player::shuttle);
		transform->setScale(box_size * 0.5f, box_size);
		break;
	}
	*/
}

inline void SceneGame::fireEnemyBullet(std::pair<std::shared_ptr<GameObject>, EnemyStats> pair) {
	std::shared_ptr<GameObject> new_bullet;
	if (!inactive_objects.empty()) {
		new_bullet = inactive_objects[inactive_objects.size() - 1];
		inactive_objects.pop_back();
	}
	else {
		new_bullet = createObject();
	}
	
	EnemyStats& enemy_stat = pair.second;
	BulletStats new_stat;
	new_stat.attack = enemy_stat.attack;
	new_stat.speed = enemy_stat.speed * 4;
	e_bullets.push_back({ new_bullet, new_stat });

	auto transform = new_bullet->getComponent<Transform>();
	transform->setScale(box_size * 0.5f, box_size * 0.5f);
	auto e_transform = pair.first->getComponent<Transform>();
	transform->setPos(e_transform->getPosition());
	transform->setRot(e_transform->getRotation());
	auto texture = new_bullet->addComponent<Texture>();
	texture->set(1);
	/*
	switch (enemy_stat.type)
	{
	case 0:
		texture->setSprite(SpriteSheet::Bullet::Red::_1);
		//transform->setScale(box_size * 0.5f, box_size);
		break;
	case 1:
		texture->setSprite(SpriteSheet::Bullet::Red::_2);
		break;
	case 2:
		texture->setSprite(SpriteSheet::Bullet::Red::_3);
		break;
	case 3:
		texture->setSprite(SpriteSheet::Bullet::Red::_5);
		//transform->setScale(box_size * 0.5f, box_size);
		break;
	case 4:
		texture->setSprite(SpriteSheet::Bullet::Red::_8);
		//transform->setScale(box_size * 0.5f, box_size);
		break;
	}
	*/
}

inline void SceneGame::move_player(float time_step) {
	float speed = 250.0f;
	float req_dir = 0.0f;
	int mov_x = 0, mov_y = 0;

	if (input.isKeyPressed(Input::Key::RIGHT) && !input.isKeyPressed(Input::Key::LEFT)) {
		mov_x = 1;
	}
	else if (input.isKeyPressed(Input::Key::LEFT) && !input.isKeyPressed(Input::Key::RIGHT)) {
		mov_x = -1;
	}

	if (input.isKeyPressed(Input::Key::UP) && !input.isKeyPressed(Input::Key::DOWN)) {
		mov_y = 1;
	}
	else if (input.isKeyPressed(Input::Key::DOWN) && !input.isKeyPressed(Input::Key::UP)) {
		mov_y = -1;
	}

	if (mov_y == 1) {
		if (mov_x == 1)
			req_dir = PI * 1.75f;
		else if (mov_x == -1)
			req_dir = PI * 0.25f;
		else
			req_dir = 0.0f;
	}
	else if (mov_y == -1) {
		if (mov_x == 1)
			req_dir = PI * 1.25f;
		else if (mov_x == -1)
			req_dir = PI * 0.75f;
		else
			req_dir = PI;
	}
	else {
		if (mov_x == 1)
			req_dir = PI * 1.5f;
		else if (mov_x == -1)
			req_dir = PI * 0.5f;
	}

	auto transform = player->getComponent<Transform>();
	float cur_dir = transform->getRotation();
	cur_dir = atan2f(sin(cur_dir), cos(cur_dir));
	cur_dir = (cur_dir < 0.0f ? 2 * PI + cur_dir : cur_dir);

	float mov = 0.0f;

	if (abs(req_dir - cur_dir) > PI * 0.05f) {
		if (abs(req_dir - cur_dir) <= PI) {
			if (req_dir - cur_dir > 0.0f)
				mov = 1.0f;
			else
				mov = -1.0f;
		}
		else {
			if (req_dir - cur_dir > 0.0f)
				mov = -1.0f;
			else
				mov = 1.0f;
		}
	}

	cur_dir += mov * PI * 0.5 * time_step;
	transform->setRot(cur_dir);
	transform->move(speed * cos(cur_dir + PI * 0.5f) * time_step, speed * sin(cur_dir + PI * 0.5f) * time_step);
}

inline void SceneGame::update_enemy(float time_step) {
	vec<2> p_pos = player->getComponent<Transform>()->getPosition();
	for (auto pair: enemies) {
		auto enemy = pair.first;
		auto& stat = pair.second;
		auto e_transform = enemy->getComponent<Transform>();
		vec<2> e_pos = e_transform->getPosition();
		float delta_x = p_pos[0] - e_pos[0];
		float delta_y = p_pos[1] - e_pos[1];
		float dir = atan2f(delta_y, delta_x);
		float x_mov = stat.speed * cos(dir) * time_step;
		float y_mov = stat.speed * sin(dir) * time_step;

		float dist = sqrtf(powf(delta_x, 2) + powf(delta_y, 2));
		if (dist > stat.speed * time_step) {
			e_transform->move(x_mov, y_mov);
			e_transform->setRot(dir + PI * 0.5f);
		}

		stat.cooldown -= time_step;
		if (stat.cooldown <= 0.0f) {
			fireEnemyBullet(pair);
			stat.resetCooldown();
			
		}
	}
}

inline void SceneGame::updateEnemyBullet(float time_step) {
	auto check = [this, &time_step](std::pair<std::shared_ptr<GameObject>, BulletStats> pair) {
		auto bullet = pair.first;
		auto stat = pair.second;
		auto transform = bullet->transform;
		auto angle = transform->getRotation();
		vec<2> delta = vec<2>(cosf(angle - PI * 0.5f), sin(angle - PI * 0.5f)) * stat.speed * time_step;
		transform->move(delta);
		auto pos = transform->getPosition();
		if (pos[0] < -800.0f || pos[0] > 800.0f || pos[1] < -450.0f || pos[1] > 450.0f) {
			transform->setPos({ 1600.0f, 900.0f });
			transform->setScale({ 0.0f, 0.0f });
			inactive_objects.push_back(bullet);
			return true;
		}
		return false;
	};
	std::remove_if(e_bullets.begin(), e_bullets.end(), check);
}

inline void SceneGame::end() {
}

inline EnemyStats::EnemyStats(int seed) :
	type(seed % 5), health(0.0f), cooldown(0.0f), speed(0.0f), attack(0.0f) {
	switch (type)
	{
	case 0:
		health = 100.0f;
		speed = 150.0f;
		attack = 50.0f;
		break;
	case 1:
		health = 200.0f;
		speed = 200.0f;
		attack = 30.0f;
		break;
	case 2:
		health = 50.0f;
		speed = 50.0f;
		attack = 150.0f;
		break;
	case 3:
		health = 150.0f;
		speed = 150.0f;
		attack = 60.0f;
		break;
	case 4:
		health = 120.0f;
		speed = 150.0f;
		attack = 80.0f;
		break;
	}
	resetCooldown();
}

inline EnemyStats::EnemyStats(const EnemyStats& other) :
	health(other.health), speed(other.speed),
	cooldown(other.cooldown), attack(other.attack), type(other.type){}

inline void EnemyStats::resetCooldown() {
	switch (type) {
	case 0:
		cooldown = 3.0f;
		break;
	case 1:
		cooldown = 5.0f;
		break;
	case 2:
		cooldown = 3.0f;
		break;
	case 3:
		cooldown = 4.0f;
		break;
	case 4:
		cooldown = 4.0f;
		break;
	}
}

#endif // !SCENE_GAME_HPP
