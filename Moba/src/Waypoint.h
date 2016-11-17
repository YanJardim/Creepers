#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "MathUtils.h"

using namespace math;

class Waypoint {
private:
	Vector2D position, *target, targetSize;
	int height, size;
	bool block, debug, visited;
	ofColor color, firstColor;

public:

	Waypoint() {};

	Waypoint(Vector2D position, int height) {
		this->position = position;
		this->height = height;
		debug = true;
		block = false;
		size = 2;
		color = ofColor().green;
		firstColor = color;
	}

	Waypoint(Vector2D position, Vector2D *target) {
		this->position = position;
		this->target = target;
		this->targetSize = Vector2D();
		this->height = UpdateHeight();
		debug = true;
		block = false;
		size = 2;
		color = ofColor().green;
		firstColor = color;
	}

	Waypoint(Vector2D position, Vector2D *target, Vector2D targetSize) {
		this->position = position;
		this->target = target;
		this->targetSize = targetSize;
		this->height = UpdateHeight();
		debug = true;
		block = false;
		size = 2;
		color = ofColor().green;
		firstColor = color;
	}

	void Update() {
		
		height = UpdateHeight();
		//cout << height << endl;
		
	}
	void Draw() {
		if (debug) {
			ofSetColor(color);
			ofDrawCircle(position.x, position.y, size);
			
			/*ofSetColor(ofColor().green);
			ofDrawCircle(target->x, target->y, 5);*/

			ofSetColor(ofColor().white);

		}
	}

	Vector2D GetPosition() {
		return position;
	}
	void SetPosition(Vector2D position) {
		this->position = position;
	}

	int GetHeight() {
		return height;
	}

	double UpdateHeight() {
		return MathUtils::GetDistance(position, *(target));
	}

	void UpdateTarget(Vector2D *target) {
		this->target = target;
	}

	bool GetBlock() {
		return block;
	}

	void SetBlock(bool newValue) {
		block = newValue;

		if (newValue) color = ofColor().red;
		else color = ofColor().green;
	}

	bool IsVisited() {
		return visited;
	}

	void SetVisited(bool newValue) {
		visited = newValue;
	}

	int GetSize() {
		return size;
	}

	void SetColor(ofColor newValue) {
		this->color = newValue;
	}

	ofColor GetColor() {
		return color;
	}

	ofColor GetFirstColor() {
		return firstColor;
	}
};