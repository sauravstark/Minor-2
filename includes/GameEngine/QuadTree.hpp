#ifndef QUAD_TREE_HPP
#define QUAD_TREE_HPP

#include "./PredefinedComponents/Collider.hpp"
#include <set>
#include <memory>
#include <stack>

class QuadTree {
public:
	QuadTree(Rect bound, unsigned ht = 0);
	bool insert(std::shared_ptr<Collider> collider);
	bool collides(std::shared_ptr<Collider> collider);
private:
	std::set<std::shared_ptr<Collider>> data;
	Rect boundary;
	QuadTree* NE, NW, SE, SW;
	unsigned height;
	bool isExpanded;
	Rect childBound[4];
	bool hasChild[4] = { false };
	void expand();
};

inline QuadTree::QuadTree(Rect bound, unsigned ht) :
	NE(nullptr), NW(nullptr), SE(nullptr), SW(nullptr),
	height(ht), isExpanded(false), boundary(bound) {

	vec<2> centre = boundary.centre;
	vec<2> span = boundary.span;

	childBound[0] = Rect({ centre[0] + span[0] / 4, centre[1] + span[1] / 4 }, { span[0] / 2, span[1] / 2 });
	childBound[1] = Rect({ centre[0] - span[0] / 4, centre[1] + span[1] / 4 }, { span[0] / 2, span[1] / 2 });
	childBound[2] = Rect({ centre[0] + span[0] / 4, centre[1] - span[1] / 4 }, { span[0] / 2, span[1] / 2 });
	childBound[3] = Rect({ centre[0] - span[0] / 4, centre[1] - span[1] / 4 }, { span[0] / 2, span[1] / 2 });
}

inline bool QuadTree::insert(std::shared_ptr<Collider> collider) {
	if (!boundary.contains(collider->getBoundary()));
		return false;

	if (!isExpanded)
		data.insert(collider);
	else if (NE->insert(collider))
		return true;
	else if (NW->insert(collider))
		return true;
	else if (SE->insert(collider))
		return true;
	else if (SW->insert(collider))
		return true;

	

	if (childBound[0].contains(collider->getBoundary))
		hasChild[0] = true;
	else if (childBound[1].contains(collider->getBoundary))
		hasChild[1] = true;
	else if (childBound[2].contains(collider->getBoundary))
		hasChild[2] = true;
	else if (childBound[3].contains(collider->getBoundary))
		hasChild[3] = true;

	unsigned sub_tree_with_child = 0;
	for (unsigned i = 0; i < 4; ++i)
		sub_tree_with_child += (hasChild[i] ? 1 : 0);
	
	if (sub_tree_with_child > 1 && height < 5)
		expand();

	return true;
}

inline bool QuadTree::collides(std::shared_ptr<Collider> collider) {
	Rect collider_boundary = collider->getBoundary();
	for (auto itr = data.begin(); itr != data.end(); ++itr) {
		if (*itr != collider && (*itr)->isColliding(collider_boundary))
			return true;
	}
	if (isExpanded) {
		if (childBound[0].collides(collider_boundary) && NE->collides(collider)) {
			return true;
		}
		if (childBound[1].collides(collider_boundary) && NW->collides(collider)) {
			return true;
		}
		if (childBound[2].collides(collider_boundary) && SE->collides(collider)) {
			return true;
		}
		if (childBound[3].collides(collider_boundary) && SW->collides(collider)) {
			return true;
		}
	}
	return false;
}

inline void QuadTree::expand() {
	vec<2> centre = boundary.centre;
	vec<2> span = boundary.span;

	NE = new QuadTree(childBound[0], height + 1);
	NW = new QuadTree(childBound[1], height + 1);
	SE = new QuadTree(childBound[2], height + 1);
	SW = new QuadTree(childBound[3], height + 1);

	std::stack<std::set<std::shared_ptr<Collider>>> remove_itrs;

	for (auto itr = data.begin(); itr != data.end(); ++itr) {
		if (NE->insert(*itr) || NW->insert(*itr) || SE->insert(*itr) || SW->insert(*itr))
			remove_itrs.push(itr);
	}
	while (!remove_itrs.empty()) {
		auto itr = remove_itrs.top();
		data.erase(itr);
		remove_itrs.pop();
	}

	isExpanded = true;
}

#endif // !QUAD_TREE_HPP
