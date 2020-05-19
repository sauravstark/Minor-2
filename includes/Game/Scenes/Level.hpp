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

struct PStat {
	float speed = 250.0f;
	float cooldown = 0.0f;
	float attack = 50.0f;
};

struct EStat {
	bool isActive;
	float speed;
	float attack;
	float health;
	float cooldown;
};

struct PBStat {
	bool isActive;
	float speed;
	float attack;
	unsigned target_index;
};

struct ExpStat {
	bool isActive = false;
	float duration = 0.0f;
};

float calcRot(float cur_dir, float des_dir, float speed, float time_step);

const unsigned e_count = 16;
const unsigned pb_count = 128;
const unsigned exp_count = 256;

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
	PStat p_stat;
	std::pair<std::shared_ptr<GameObject>, EStat> enemies[e_count] = { { nullptr, EStat() } };
	std::pair<std::shared_ptr<GameObject>, PBStat> p_bullets[pb_count] = { { nullptr, PBStat() } };
	std::pair<std::shared_ptr<GameObject>, ExpStat> explosions[exp_count] = { { nullptr, ExpStat() } };

	void updatePlayer(float time_step);
	void updateEnemies(float time_step);
	void updatePlayerBullets(float time_step);
	void updateEnemyBullets(float time_step);
	void updateExplosions(float time_step);

	void movePlayer(float time_step);
	void firePlayerBullet();
	void spawnEnemy();
	void moveEnemy(float time_step);
	void killEnemy(unsigned index);
	void killPlayer();

	void createExplosion(vec<2> pos, bool large);

	void findPBTarget(unsigned b_index);
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
		for (unsigned i = 0; i < e_count; ++i) {
			enemies[i].first = createObject();
			enemies[i].first->addComponent<Texture>()->set(0);
			enemies[i].second.isActive = false;
		}
	}
	//player bullets
	{
		for (unsigned i = 0; i < pb_count; ++i) {
			p_bullets[i].first = createObject();
			p_bullets[i].first->addComponent<Texture>()->set(1);
			p_bullets[i].second.isActive = false;
		}
	}
	//explosions
	{
		for (unsigned i = 0; i < exp_count; ++i) {
			explosions[i].first = createObject();
			explosions[i].first->addComponent<Texture>()->set(1);
			auto animation = explosions[i].first->addComponent<Animation>();
			auto b_explosion = std::make_shared<FrameSet>(8, Repeat::FORWARD);
			b_explosion->setFrameData(0, Frame(SpriteSheet::Explosion_Big::Orange::_1, 0.125f));
			b_explosion->setFrameData(1, Frame(SpriteSheet::Explosion_Big::Orange::_2, 0.125f));
			b_explosion->setFrameData(2, Frame(SpriteSheet::Explosion_Big::Orange::_3, 0.125f));
			b_explosion->setFrameData(3, Frame(SpriteSheet::Explosion_Big::Orange::_4, 0.125f));
			b_explosion->setFrameData(4, Frame(SpriteSheet::Explosion_Big::Orange::_5, 0.125f));
			b_explosion->setFrameData(5, Frame(SpriteSheet::Explosion_Big::Orange::_6, 0.125f));
			b_explosion->setFrameData(6, Frame(SpriteSheet::Explosion_Big::Orange::_7, 0.125f));
			b_explosion->setFrameData(7, Frame(SpriteSheet::Explosion_Big::Orange::_8, 0.125f));
			auto e_explosion = std::make_shared<FrameSet>(8, Repeat::FORWARD);
			e_explosion->setFrameData(0, Frame(SpriteSheet::Explosion_Small::Red::_1, 0.125f));
			e_explosion->setFrameData(1, Frame(SpriteSheet::Explosion_Small::Red::_2, 0.125f));
			e_explosion->setFrameData(2, Frame(SpriteSheet::Explosion_Small::Red::_3, 0.125f));
			e_explosion->setFrameData(3, Frame(SpriteSheet::Explosion_Small::Red::_4, 0.125f));
			e_explosion->setFrameData(4, Frame(SpriteSheet::Explosion_Small::Red::_5, 0.125f));
			e_explosion->setFrameData(5, Frame(SpriteSheet::Explosion_Small::Red::_6, 0.125f));
			e_explosion->setFrameData(6, Frame(SpriteSheet::Explosion_Small::Red::_7, 0.125f));
			e_explosion->setFrameData(7, Frame(SpriteSheet::Explosion_Small::Red::_8, 0.125f));
			animation->addAnimation("small", b_explosion);
			animation->addAnimation("large", e_explosion);
			explosions[i].second.isActive = false;
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
	updateExplosions(time_step);
}

inline void SceneGame::updatePlayer(float time_step) {
	//move
	movePlayer(time_step);
	//fire bullets
	p_stat.cooldown -= time_step;
	firePlayerBullet();
}

inline void SceneGame::updateEnemies(float time_step) {
	//spawn enemy
	spawn_cooldown -= time_step;
	if (spawn_cooldown <= 0.0f) {
		spawnEnemy();
	}
	
	//move enemy
	moveEnemy(time_step);

	//fire bullets
	//fireEnemyBullet();
}

inline void SceneGame::updatePlayerBullets(float time_step) {
	for (unsigned i = 0; i < pb_count; ++i) {
		if (p_bullets[i].second.isActive) {
			unsigned target_index = p_bullets[i].second.target_index;
			auto b_transform = p_bullets[i].first->transform;
			auto e_transform = enemies[target_index].first->transform;
			auto b_stat = p_bullets[i].second;
			float cur_dir = b_transform->getRotation();
			auto disp = e_transform->getPosition() - b_transform->getPosition();
			float speed = b_stat.speed;
			if (speed * time_step < sqrt(disp[0] * disp[0] + disp[1] * disp[1])) {
				float req_dir = atan2f(disp[1], disp[0]) - PI * 0.5f;
				float nex_dir = calcRot(cur_dir, req_dir, b_stat.speed, time_step);
				b_transform->setRot(nex_dir);
				b_transform->move(speed * cos(nex_dir + PI * 0.5f) * time_step, speed * sin(nex_dir + PI * 0.5f) * time_step);
			} else {
				createExplosion(b_transform->getPosition(), true);
				p_bullets[i].second.isActive = false;
				p_bullets[i].first->transform->setPos(1000.0f, 1000.0f);
				killEnemy(target_index);
			}
		}
	}
}

inline void SceneGame::updateEnemyBullets(float time_step) {
}

inline void SceneGame::updateExplosions(float time_step) {
	for (unsigned i = 0; i < exp_count; ++i) {
		if (explosions[i].second.isActive) {
			explosions[i].second.duration += time_step;
			if (explosions[i].second.duration > 1.0f) {
				explosions[i].second.isActive = false;
				explosions[i].second.duration = 0.0f;
				explosions[i].first->transform->setScale(0.0f, 0.0f);
				explosions[i].first->transform->setPos(1000.0f, 1000.0f);
			}
		}
	}
}

inline void SceneGame::movePlayer(float time_step) {
	float speed = p_stat.speed;
	auto transform = player->getComponent<Transform>();
	float cur_dir = transform->getRotation();
	cur_dir = atan2f(sin(cur_dir), cos(cur_dir));
	cur_dir = (cur_dir < 0.0f ? 2 * PI + cur_dir : cur_dir);
	float req_dir = cur_dir;
	bool N = input.isKeyPressed(Input::Key::UP);
	bool E = input.isKeyPressed(Input::Key::RIGHT);
	bool W = input.isKeyPressed(Input::Key::LEFT);
	bool S = input.isKeyPressed(Input::Key::DOWN);

	if		(N && !S && !E && !W)	req_dir = PI * 0.00f;
	else if (S && !N && !E && !W)	req_dir = PI * 1.00f;
	else if (E && !W && !N && !S)	req_dir = PI * 1.50f;
	else if (W && !E && !N && !S)	req_dir = PI * 0.50f;
	else if (N &&  E && !S && !W)	req_dir = PI * 1.75f;
	else if (N &&  W && !S && !E)	req_dir = PI * 0.25f;
	else if (S &&  E && !S && !W)	req_dir = PI * 1.25f;
	else if (S &&  W && !S && !E)	req_dir = PI * 0.25f;

	float nex_dir = calcRot(cur_dir, req_dir, speed, time_step);

	transform->setRot(nex_dir);
	transform->move(speed * cos(nex_dir + PI * 0.5f) * time_step, speed * sin(nex_dir + PI * 0.5f) * time_step);
}

inline void SceneGame::firePlayerBullet() {
	if (p_stat.cooldown <= 0.0f && input.isKeyPressed(Input::Key::LSHIFT)) {
		for (unsigned int i = 0; i < pb_count; ++i) {
			if (p_bullets[i].second.isActive == false) {
				p_bullets[i].second.isActive = true;
				p_bullets[i].second.speed = p_stat.speed * 2;
				p_bullets[i].second.attack = p_stat.attack;

				auto bullet = p_bullets[i].first;
				auto transform = bullet->getComponent<Transform>();
				auto texture = bullet->getComponent<Texture>();
				auto p_transform = player->getComponent<Transform>();
				auto b_pos = p_transform->getPosition();
				auto b_rot = p_transform->getRotation();

				bool key_w = input.isKeyPressed(Input::Key::ALPH_W);
				bool key_s = input.isKeyPressed(Input::Key::ALPH_S);
				bool key_a = input.isKeyPressed(Input::Key::ALPH_A);
				bool key_d = input.isKeyPressed(Input::Key::ALPH_D);

				if (key_w && !key_s && !key_a && !key_d)	b_rot = PI * 0.00f;
				if (key_s && !key_w && !key_a && !key_d)	b_rot = PI * 1.00f;
				if (key_a && !key_d && !key_w && !key_s)	b_rot = PI * 0.50f;
				if (key_d && !key_a && !key_w && !key_s)	b_rot = PI * 1.50f;
				if (key_w &&  key_a && !key_s && !key_d)	b_rot = PI * 0.25f;
				if (key_w &&  key_d && !key_s && !key_a)	b_rot = PI * 1.75f;
				if (key_s &&  key_a && !key_w && !key_d)	b_rot = PI * 0.75f;
				if (key_s &&  key_d && !key_w && !key_a)	b_rot = PI * 1.25f;
				
				transform->setPos(b_pos);
				transform->setRot(b_rot);
				transform->setScale(box_size * 0.5f, box_size * 0.5f);
				texture->set(1);
				texture->setSprite(SpriteSheet::Bullet::Blue::_3);
				findPBTarget(i);
				break;
			}
		}
		p_stat.cooldown = 1.0f;
	}
}

inline void SceneGame::spawnEnemy() {
	for (unsigned i = 0; i < e_count; ++i) {
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

inline void SceneGame::moveEnemy(float time_step) {
	auto p_pos = player->getComponent<Transform>()->getPosition();
	for (unsigned i = 0; i < e_count; ++i) {
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

inline void SceneGame::killEnemy(unsigned index) {
	enemies[index].second.isActive = false;
	enemies[index].first->transform->setPos(1000.0f, 1000.0f);
}

inline void SceneGame::killPlayer() {
}

inline void SceneGame::createExplosion(vec<2> pos, bool large) {
	for (unsigned i = 0; i < exp_count; ++i) {
		if (!explosions[i].second.isActive) {

			explosions[i].second.isActive = true;
			explosions[i].second.duration = 0.0f;
			auto explosion = explosions[i].first;
			explosion->transform->setPos(pos);
			if (large) {
				explosion->getComponent<Transform>()->setScale(box_size, box_size);
				explosion->getComponent<Animation>()->setAnimation("large");
			} else {
				explosion->getComponent<Transform>()->setScale(box_size * 0.5f, box_size * 0.5f);
				explosion->getComponent<Animation>()->setAnimation("small");
			}
			return;
		}
	}
}

inline void SceneGame::findPBTarget(unsigned b_index) {
	unsigned nearest = 0;
	float max_dot_prod = -1;
	auto b_transform = p_bullets[b_index].first->transform;
	float b_dir = b_transform->getRotation() + PI * 0.5f;
	for (unsigned i = 0; i < e_count; ++i) {
		if (enemies[i].second.isActive) {
			auto e_transform = enemies[i].first->transform;
			auto norm_disp = (e_transform->getPosition() - b_transform->getPosition());
			norm_disp.normalize();
			auto norm_dir = vec<2>(cosf(b_dir), sinf(b_dir));
			auto dot_vec = norm_dir * norm_disp;
			auto dot_prod = dot_vec[0] + dot_vec[1];
			if (dot_prod > max_dot_prod) {
				max_dot_prod = dot_prod;
				nearest = i;
			}
		}
	}
	p_bullets[b_index].second.target_index = nearest;
}

float calcRot(float cur_dir, float req_dir, float speed, float time_step) {
	
	float rf = speed * speed / 100000.0f;
	
	cur_dir = atan2f(sin(cur_dir), cos(cur_dir));
	cur_dir = (cur_dir < 0.0f ? 2 * PI + cur_dir : cur_dir);
	req_dir = atan2f(sin(req_dir), cos(req_dir));
	req_dir = (req_dir < 0.0f ? 2 * PI + req_dir : req_dir);

	if (abs(req_dir - cur_dir) > PI * rf * time_step) {
		if (abs(req_dir - cur_dir) <= PI)
			cur_dir += sgn(req_dir - cur_dir) * PI * rf * time_step;
		else
			cur_dir += sgn(cur_dir - req_dir) * PI * rf * time_step;
	} else {
		cur_dir = req_dir;
	}

	return cur_dir;
}

#endif // !SCENE_GAME_HPP
