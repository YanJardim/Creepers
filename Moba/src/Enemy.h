#pragma once

#include "GameObject.h"
#include "Waypoint.h"
#include "WaypointManager.h"

#define WMANAGER WaypointManager::GetInstance()
#define EMANAGER EnemyManager::GetInstance()


class Enemy : public GameObject{
private:
	Waypoint target;
	Vector2D velocity;

	ofPolyline vision, box;
	ofPath visionPath, graphicsPath;

	int speed, angle, index, visionSize;
	bool canRotate;

	
public:
	Enemy() {}
	Enemy(Vector2D *position, int speed, int size, string tag) : GameObject(position, Vector2D(size, size), tag){
		angle = 0;
		this->speed = speed;
		this->visionSize = size;
		
		CreateTriangle(vision, visionSize);
		CreateSquare(size);
		FillPoly(visionPath, vision, ofColor().gray);
		FillPoly(graphicsPath, graphics, ofColor().black);
		canRotate = false;
		//target = *(position);

		target.SetPosition(Vector2D(0.f, position->y));
		velocity = normalize(MathUtils::GetDirection(*(position), target.GetPosition()));
		
		
	}


	void Start() override {
		
	}

	void Update() override {
		UpdateTarget();
		Follow();
		CreateSquare(graphics, size.x);
		CreateTriangle(vision,size.x);
		FillPolyClear(visionPath, vision, ofColor().darkGray);
		FillPolyClear(graphicsPath, graphics, ofColor().red);
		
	}

	void LookAt(Vector2D target) {
		float newAng = MathUtils::GetAngle(*(this->position), target);
		angle = newAng;
	}

	void Follow() {
		velocity = normalize(MathUtils::GetDirection(*(position), target.GetPosition()));

		if (MathUtils::GetDistance(*(position), target.GetPosition()) > 2.f && !target.GetBlock()) {
				*(position) += velocity * ofGetLastFrameTime() * speed;
		}
		//else cout << MathUtils::GetDistance(*(position), target.GetPosition()) << endl;
	}

	void Draw() override {
	
		//if (angle > 360) angle = 0;

		ofPushMatrix();

			ofTranslate(position->x, position->y);
			ofRotate(angle - 180);

			ofPushMatrix();

				ofTranslate(-position->x,-position->y);
				graphicsPath.draw();
				visionPath.draw();
				//DrawCollider();

			ofPopMatrix();

		ofPopMatrix();
		
		
		
	}

	void DrawCollider() {
		Vector2D minBounds = Vector2D(GetGraphics().getBoundingBox().getMinX(), GetGraphics().getBoundingBox().getMinY());
		Vector2D maxBounds = Vector2D(GetGraphics().getBoundingBox().getMaxX(), GetGraphics().getBoundingBox().getMaxY());
		CreateSquare(box, maxBounds.x - minBounds.x, maxBounds.y - minBounds.y);
		ofSetColor(ofColor().green);

		box.draw();

		ofSetColor(ofColor().white);
	}

	void SetTarget(Waypoint target) {
		this->target = target;
	}

	Waypoint GetTarget() {
		return this->target;
	}

	void SetVelocity(Vector2D newValue) {
		this->velocity = newValue;
	}

	

	void UpdateTarget() {
		Waypoint target = WMANAGER->GetNearWaypoint(*(GetPosition()));
		SetTarget(target);
		LookAt(target.GetPosition());
	}

	void SetSpeed(int newValue) {
		this->speed = newValue;
	}
	int GetSpeed() {
		return speed;
	}

	int GetIndex() {
		return index;
	}
	void SetIndex(int newValue) {
		this->index = newValue;
	}

	
};