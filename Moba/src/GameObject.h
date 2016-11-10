#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "MathUtils.h"

using namespace math;

 class GameObject {
protected:

	Vector2D *position, size;

	ofRectangle graphics;
	ofImage image;
public:

	GameObject() {};
	GameObject(Vector2D *position, Vector2D size) {
		this->position = position;
		this->size = size;

	}
	GameObject(Vector2D *position, ofImage image) {
		this->position = position;
		this->image = image;

	}

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() {
		ofDrawRectangle(position->x, position->y, size.x, size.y);
		
	}


	Vector2D *GetPosition() {
		return position;
	}
	Vector2D GetSize() {
		return size;
	}

	Vector2D GetCenter() {
		return size / 2;
	}
	

};