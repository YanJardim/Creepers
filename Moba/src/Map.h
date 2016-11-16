#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "GameObject.h"

using namespace math;

class Map : public GameObject{
private:

	ofImage mapImage;
	Vector2D enemyBase, base;

	int baseDistance = 30;
public:
	Map() {};

	Map(int x, int y, ofImage image, string tag) : GameObject(new Vector2D(x, y), Vector2D(image.getWidth(), image.getHeight()), tag) {
		this->mapImage = image;
		base = Vector2D(baseDistance, ofGetWindowHeight() - baseDistance);
		enemyBase = Vector2D(ofGetWindowWidth() - baseDistance, baseDistance);

	}
	Map(Vector2D *position, ofImage image, string tag) : GameObject(position, Vector2D(image.getWidth(), image.getHeight()), tag) {
		this->mapImage = image;
	}

	// Inherited via GameObject
	void Start() override {

	}
	void Update() override {

	}
	void Draw() override {
		DrawImage(mapImage);
	}

	Vector2D GetEnemyBase() {
		return enemyBase;
	}
	Vector2D GetBase() {
		return base;
	}

	int GetBaseDistance() {
		return baseDistance;
	}

};