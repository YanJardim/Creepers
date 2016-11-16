#pragma once

#include "GameObject.h"

using namespace math;

class Player : public GameObject{

private:
	Vector2D direction, velocity, mouse;
	int speed;
	bool target;
	ofPath path;

public:
	Player() {
		this->target = false;
	}
	Player(int x, int y, int speed, int size, string tag) : GameObject(new Vector2D(x, y), Vector2D(size, size), tag) {
		this->speed = speed;
		this->size = Vector2D(size, size);
		this->target = false;
		//this->graphics = ofRectangle(x, y, size.x, size.y);
		
		CreateSquare(size);
		FillPoly(path, graphics, ofColor().darkGray);
		this->velocity = Vector2D(0, 0);
	}
	Player(Vector2D *position, int speed, int size, string tag) : GameObject(position, Vector2D(size, size), tag){
		this->speed = speed;
		this->target = false;
		//this->graphics = ofRectangle(position->x, position->y, size.x, size.y);
		CreateSquare(size);
		FillPoly(path, graphics, ofColor().darkGray);
		this->velocity = Vector2D(0, 0);

	}

	void Start() {

	}

	void Draw() {
		//ofDrawRectangle(graphics);
		graphics.draw();
		path.draw();

	}
	void Update() {

		if (mouse.size() > 0.1) {
			auto direction = normalize(mouse - *(position));
			velocity = direction * speed;
			//mouse = Vector2D();
		}
		double d = MathUtils::GetDistance(*(position), mouse);
		//cout << d << endl;
		if(d > 2)
			*(position) += velocity * ofGetLastFrameTime();

		//graphics = ofRectangle(position->x, position->y, size.x, size.y);
		CreateSquare(size.x);
		FillPolyClear(path, graphics, ofColor().darkGray);
	}
	void Move(Vector2D mouse) {
		this->mouse = mouse;
		
		target = true;
	}

	Vector2D* GetPosition() {
		return position;
	}

	Vector2D GetSize() {
		return this->size;
	}

	
	
};