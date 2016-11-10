#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "MathUtils.h"

using namespace math;

class Waypoint {
private:
	Vector2D position, *target;
	int height;
	bool block, debug;

public:

	Waypoint(Vector2D position, int height) {
		this->position = position;
		this->height = height;
		debug = true;
		block = false;
	}

	Waypoint(Vector2D position, Vector2D *target) {
		this->position = position;
		this->target = target;
		this->height = UpdateHeight();
		debug = true;
		block = false;
	}

	void Update() {
		
		height = UpdateHeight();
		cout << height << endl;
		
	}
	void Draw() {
		if (debug) {
			ofSetColor(ofColor().red);
			ofDrawCircle(position.x, position.y, 10);
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
};