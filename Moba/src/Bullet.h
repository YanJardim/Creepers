#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "MathUtils.h"

class Bullet : public GameObject{
private:
	int angle, speed, index;
	Vector2D *target = nullptr, velocity;
	bool playerB;
public:
	Vector2D p;

	Bullet() {};

	Bullet(int x, int y, int speed, Vector2D *target, Vector2D size, string tag, int index) : GameObject(new Vector2D(x, y), size, tag) {
		this->speed = speed;
		this->target = target;
		this->index = index;

		playerB = false;

	}

	void LookAt(Vector2D target) {
		float newAng = MathUtils::GetAngle(*(this->position), target);
		angle = newAng;
	}

	// Inherited via GameObject
	void Start() override {
		velocity = normalize(MathUtils::GetDirection(*(position), *(target)));
		LookAt(*(target));
		CreateSquare(size.x, size.y);
	}
	void Update() override {
		//velocity = normalize(MathUtils::GetDirection(*(position), *(target)));

		*(position) += velocity * ofGetLastFrameTime() * speed;

		/*cout << "Vel: " << velocity << endl;
		cout << "Pos: " << *(position) << endl;
		cout << "Speed: " << speed << endl;*/

		CreateSquare(size.x, size.y);


	}
	void Draw() override {
		//graphics.draw();
		ofPushMatrix();

			ofTranslate(position->x, position->y);
			ofRotate(angle - 180);

			ofPushMatrix();

				ofTranslate(-position->x, -position->y);
				graphics.draw();
				

			ofPopMatrix();

		ofPopMatrix();
	}

	Vector2D *GetTarget() {
		return target;
	}

	int GetIndex() {
		return index;
	}
	void SetIndex(int newValue) {
		this->index = newValue;
	}

	void SetPlayerB(bool newValue) {
		this->playerB = newValue;
	}
	bool GetPlayerB() {
		return this->playerB;
	}
};