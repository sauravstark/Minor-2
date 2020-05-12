#ifndef KEYBOARD_MOVEMENT
#define KEYBOARD_MOVEMENT

#include "..//GameObject.hpp"
#include "..//Component.hpp"
#include "..//Input.hpp"

class KeyboardMovement : public Component {
public:
	KeyboardMovement(GameObject* owner);

	void setInput(Input* input);
	void setMovementSpeed(float moveSpeed);

	void update(float time_step) override;

private:
	float moveSpeed;
	Input* input;
};

KeyboardMovement::KeyboardMovement(GameObject *owner) :
	Component(owner), moveSpeed(100.0f) {}

void KeyboardMovement::setInput(Input* input) {
	this->input = input;
}

void KeyboardMovement::setMovementSpeed(float moveSpeed) {
	this->moveSpeed = moveSpeed;
}

void KeyboardMovement::update(float time_step) {
	if (input == nullptr)
		return;

	float x_move = 0.0f, y_move = 0.0f;

	if (input->isKeyPressed(Input::Key::LEFT) && !input->isKeyPressed(Input::Key::RIGHT))
		x_move = -moveSpeed;
	else if (input->isKeyPressed(Input::Key::RIGHT) && !input->isKeyPressed(Input::Key::LEFT))
		x_move = moveSpeed;

	if (input->isKeyPressed(Input::Key::DOWN) && !input->isKeyPressed(Input::Key::UP))
		y_move = -moveSpeed;
	else if (input->isKeyPressed(Input::Key::UP) && !input->isKeyPressed(Input::Key::DOWN))
		y_move = moveSpeed;

	vec<2> frame_move;

	if (x_move != 0 && y_move != 0)
		frame_move = { x_move * time_step / 1.414f, y_move * time_step / 1.414f };
	else
		frame_move = { x_move * time_step, y_move * time_step };

	owner->transform->move(frame_move);
}

#endif // !KEYBOARD_MOVEMENT
