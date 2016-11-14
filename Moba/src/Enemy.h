#pragma once

#include "GameObject.h"


class Enemy : public GameObject{
private:
	int speed, angle;
	Vector2D target, velocity;
	ofPolyline vision;
	ofPath visionPath, graphicsPath;
	int visionSize;
	bool canRotate;
	
	
public:
	Enemy() {}
	Enemy(Vector2D *position, int speed, int size) : GameObject(position, Vector2D(size, size)){
		angle = 0;
		this->speed = speed;
		this->visionSize = size;
		
		CreateTriangle(vision, visionSize);
		CreateSquare(size);
		FillPoly(visionPath, vision, ofColor().gray);
		FillPoly(graphicsPath, graphics, ofColor().black);
		canRotate = false;
		//target = *(position);

		target = Vector2D(position->x, position->y);
		velocity = normalize(MathUtils::GetDirection(*(position), target));
		
	}


	void Start() override {
		
	}

	void Update() override {
		Follow();
		CreateSquare(graphics, size.x);
		CreateTriangle(vision,size.x);
		
	}

	void LookAt(Vector2D target) {
		float newAng = MathUtils::GetAngle(*(this->position), target);
		angle = newAng;
	}

	void Follow() {
		velocity = normalize(MathUtils::GetDirection(*(position), target));

		if(MathUtils::GetDistance(*(position), target)> 2.f)
			*(position) += velocity * ofGetLastFrameTime() * speed;
	}

	void Draw() override {
	
		//if (angle > 360) angle = 0;

		ofPushMatrix();
			ofTranslate(position->x, position->y);
			ofRotate(angle - 180);
			ofPushMatrix();
			ofTranslate(-position->x,-position->y);
				graphics.draw();
				vision.draw();
			ofPopMatrix();
		ofPopMatrix();
		
		/*ofPushMatrix();
			
			ofTranslate(position->x, position->y);

			ofRotate(angle - 180);
	
			

			ofSetColor(0, 0, 255);

			ofPushMatrix();

				ofTranslate(-position->x, -position->y);
				graphics.draw();
				graphicsPath.draw();

			ofPopMatrix();

			ofSetColor(0, 255, 0);

			ofPushMatrix();
				
				//visionPath.draw();
				
			ofPopMatrix();
			
		ofPopMatrix();*/

		
	}

	void SetTarget(Vector2D target) {
		this->target = target;
		
	}

	bool CheckCollision() {
		
	}

	
};