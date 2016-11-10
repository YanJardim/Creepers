#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "MathUtils.h"

using namespace math;

class Player {

private:
	ofRectangle graphics;
	Vector2D *position, direction, velocity, mouse, center;
	int speed, size;
	bool target;

public:
	Player() {
		this->target = false;
	}
	Player(int x, int y, int speed, int size) {
		position = new Vector2D();
		this->position->x = x;
		this->position->y = y;
		this->speed = speed;
		this->size = size;
		this->target = false;
		this->graphics = ofRectangle(x, y, size, size);
		this->velocity = Vector2D(0, 0);
		this->center = Vector2D(size / 2, size / 2);
	}
	Player(Vector2D *position, int speed) {
		this->position = position;
		this->speed = speed;
		this->target = false;
		this->graphics = ofRectangle(position->x, position->y, size, size);
		this->velocity = Vector2D(0, 0);
		this->center = Vector2D(size / 2, size / 2);
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

		graphics = ofRectangle(position->x, position->y, size, size);
	}
	void Move(Vector2D mouse) {
		this->mouse = mouse - center;
		
		target = true;
	}

	Vector2D* GetPosition() {
		return position;
	}

	Vector2D GetSize() {
		return Vector2D(size, size);
	}
	Vector2D GetCenter() {
		return Vector2D(size/2, size/2);
	}

};