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
	const unsigned int count = 2;
	const unsigned int row_count = 9 * count;
	const unsigned int col_count = 16 * count;
	const float l = 2.0f / col_count;
	const float b = 2.0f / row_count;

	vertices.resize(objects.size() * 4);
	int index = 0;
	for (auto itr = objects.begin(); itr != objects.end(); ++itr) {
		auto transform = (*itr)->getComponent<Transform>();
		auto texture = (*itr)->getComponent<Texture>();

		vec<2> pos = transform->getPosition();
		vec<4> col, spr;
		float texID = -1.0f;
		if (texture != nullptr) {
			col = texture->getColor();
			spr = texture->getSprite();
			texID = texture->getTextureID();
		}

		vec<3> pos1 = { pos[0] - l / 2, pos[1] - b / 2, 0.0f };
		vec<3> pos2 = { pos[0] + l / 2, pos[1] - b / 2, 0.0f };
		vec<3> pos3 = { pos[0] - l / 2, pos[1] + b / 2, 0.0f };
		vec<3> pos4 = { pos[0] + l / 2, pos[1] + b / 2, 0.0f };

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
