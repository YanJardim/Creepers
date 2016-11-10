#pragma once

#include "GameObject.h"

using namespace math;

class Player : public GameObject{

private:
	Vector2D direction, velocity, mouse;
	int speed;
	bool target;

public:
	Player() {
		this->target = false;
	}
	Player(int x, int y, int speed, Vector2D size) : GameObject(new Vector2D(x, y), size) {
		position = new Vector2D();

		this->speed = speed;
		this->size = size;
		this->target = false;
		this->graphics = ofRectangle(x, y, size.x, size.y);
		this->velocity = Vector2D(0, 0);
	}
	Player(Vector2D *position, int speed, Vector2D size) : GameObject(position, size){
		this->speed = speed;
		this->target = false;
		this->graphics = ofRectangle(position->x, position->y, size.x, size.y);
		this->velocity = Vector2D(0, 0);

	}

	void Start() {

	}

	void Draw() {
		ofDrawRectangle(graphics);
	}
	void Update() {

		if (mouse.size() > 0.1) {
			auto direction = normalize(mouse - *(position));
			velocity = direction * speed;
			//mouse = Vector2D();
		}
		double d = MathUtils::GetDistance(*(position), mouse);
		cout << d << endl;
		if(d > 2)
			*(position) += velocity * ofGetLastFrameTime();

		graphics = ofRectangle(position->x, position->y, size.x, size.y);
	}
	void Move(Vector2D mouse) {
		this->mouse = mouse - GetCenter();
		
		target = true;
	}

	Vector2D* GetPosition() {
		return position;
	}

	Vector2D GetSize() {
		return this->size;
	}
	
};