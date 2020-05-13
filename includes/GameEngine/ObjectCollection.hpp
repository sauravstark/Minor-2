#ifndef OBJECT_COLLECTION_HPP
#define OBJECT_COLLECTION_HPP

#include "./GameObject.hpp"
#include "..//Datatypes/Vertex.hpp"
#include "..//GameEngine/PredefinedComponents/Transform.hpp"
#include "..//GameEngine/PredefinedComponents/Texture.hpp"
#include <memory>
#include <vector>
#include <set>

class ObjectCollection {
public:
	void add(std::shared_ptr<GameObject> object);

	void update(float time_step);
	void lateUpdate(float time_step);
	void draw(Window& window);

	void processAddedObjects();
	void processRemovedObjects();

	void calculateVertices(std::vector<Vertex>& vertices) const;

private:
	std::set<std::shared_ptr<GameObject>> objects;
	std::vector<std::shared_ptr<GameObject>> added_objects;
	std::vector<std::shared_ptr<GameObject>> removed_objects;
};

inline void ObjectCollection::add(std::shared_ptr<GameObject> obj) {
	added_objects.push_back(obj);
}

inline void ObjectCollection::update(float time_step) {
	for (auto& obj : objects) {
		obj->update(time_step);
	}
}

inline void ObjectCollection::lateUpdate(float time_step) {
	for (auto& obj : objects) {
		obj->lateUpdate(time_step);
	}
}

inline void ObjectCollection::draw(Window& window) {
	//
}

inline void ObjectCollection::processAddedObjects() {
	if (added_objects.size() > 0) {
		for (const auto& obj : added_objects) {
			obj->awake();
		}

		for (const auto& obj : added_objects) {
			obj->start();
		}

		for (const auto& obj : added_objects) {
			objects.insert(obj);
		}

		added_objects.clear();
	}
}

inline void ObjectCollection::processRemovedObjects() {
	if (removed_objects.size() > 0) {
		for (const auto& obj : removed_objects) {
			objects.erase(obj);
		}

		removed_objects.clear();
	}
}

inline void ObjectCollection::calculateVertices(std::vector<Vertex>& vertices) const {

	vertices.resize(objects.size() * 4);
	int index = 0;
	for (auto itr = objects.begin(); itr != objects.end(); ++itr) {
		auto transform = (*itr)->getComponent<Transform>()->getTransform();
		auto texture = (*itr)->getComponent<Texture>();

		vec<4> col, spr;
		float texID = -1.0f;
		if (texture != nullptr) {
			col = texture->getColor();
			spr = texture->getSprite();
			texID = texture->getTextureID();
		}
		float pos_x = transform[0][0], pos_y = transform[0][1], pos_z = transform[0][2];
		float ang_x = transform[1][0], ang_y = transform[1][1], ang_z = transform[1][2];
		float siz_x = transform[2][0], siz_y = transform[2][1], siz_z = transform[2][2];

		mat<4> T = {
			{ 1.00f, 0.00f, 0.00f, pos_x },
			{ 0.00f, 1.00f, 0.00f, pos_y },
			{ 0.00f, 0.00f, 1.00f, pos_z },
			{ 0.00f, 0.00f, 0.00f, 1.00f },
		};

		mat<4> R = {
			{
				cos(ang_x) * cos(ang_y),
				cos(ang_x) * sin(ang_y) * sin(ang_z) - sin(ang_x) * cos(ang_z),
				cos(ang_x) * sin(ang_y) * cos(ang_z) + sin(ang_x) * sin(ang_z),
				0.00f
			},
			{
				sin(ang_x) * cos(ang_y),
				sin(ang_x) * sin(ang_y) * sin(ang_z) + cos(ang_x) * cos(ang_z),
				sin(ang_x) * sin(ang_y) * cos(ang_z) - cos(ang_x) * sin(ang_z),
				0.00f
			},
			{
				-sin(ang_y),
				cos(ang_y) * sin(ang_z),
				cos(ang_y) * cos(ang_z),
				0.00f
			},
			{	
				0.00f, 0.00f, 0.00f, 1.00f
			}
		};

		mat<4> S = {
			{ siz_x, 0.00f, 0.00f, 0.00f },
			{ 0.00f, siz_y, 0.00f, 0.00f },
			{ 0.00f, 0.00f, siz_z, 0.00f },
			{ 0.00f, 0.00f, 0.00f, 1.00f },
		};

		mat<4> transform_matrix = T * R * S;

		vec<4> pos1 = transform_matrix * vec<4>(-0.50f, -0.50f, 0.00f, 1.00f);
		vec<4> pos2 = transform_matrix * vec<4>( 0.50f, -0.50f, 0.00f, 1.00f);
		vec<4> pos3 = transform_matrix * vec<4>(-0.50f,  0.50f, 0.00f, 1.00f);
		vec<4> pos4 = transform_matrix * vec<4>( 0.50f,  0.50f, 0.00f, 1.00f);

		vec<3> tex1 = { spr[0], spr[1], texID };
		vec<3> tex2 = { spr[2], spr[1], texID };
		vec<3> tex3 = { spr[0], spr[3], texID };
		vec<3> tex4 = { spr[2], spr[3], texID };

		vertices[index++] = { pos1, col, tex1 };
		vertices[index++] = { pos2, col, tex2 };
		vertices[index++] = { pos3, col, tex3 };
		vertices[index++] = { pos4, col, tex4 };
	}
}

#endif // !OBJECT_COLLECTION_HPP
