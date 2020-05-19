#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "..//GameObject.hpp"
#include "..//Component.hpp"
#include "..//FrameSet.hpp"
#include "./Texture.hpp"

#include <memory>
#include <map>
#include <utility>
#include <string>

class Animation : public Component {
public:
	Animation(GameObject* owner);
	void awake() override;
	void update(float time_step) override;

	void addAnimation(std::string state, std::shared_ptr<FrameSet> frame_set);
	void setAnimation(std::string state);
	const std::string& getAnimationState() const;
private:
	std::shared_ptr<Texture> sprite_sheet;
	std::map<std::string, std::shared_ptr<FrameSet>> animations;
	std::pair<std::string, std::shared_ptr<FrameSet>> active_animation;
};

inline Animation::Animation(GameObject* owner) :
	Component(owner), active_animation("NONE", nullptr) {}

inline void Animation::awake() {
	sprite_sheet = owner->getComponent<Texture>();
}

inline void Animation::update(float time_step) {
	if (active_animation.first != "NONE") {
		active_animation.second->update(time_step);
		sprite_sheet->setSprite(active_animation.second->getCurrentFrame());
	}
}

inline void Animation::addAnimation(std::string state, std::shared_ptr<FrameSet> frame_set) {
	auto inserted = animations.insert(std::make_pair(state, frame_set));
}

inline void Animation::setAnimation(std::string state) {
	if (active_animation.first != state) {
		auto animation = animations.find(state);
		if (animation != animations.end()) {
			active_animation.first = animation->first;
			active_animation.second = animation->second;
			active_animation.second->reset();
		}
	}
}

inline const std::string& Animation::getAnimationState() const {
	return active_animation.first;
}

#endif // !ANIMATION_HPP
