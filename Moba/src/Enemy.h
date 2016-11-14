#pragma once

#include "GameObject.h"

using namespace math;

class Enemy : public GameObject{
private:
	int speed, angle;
	Vector2D p1, p2, p3;
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
		/*p1.set((position->x + GetCenter().x), (position->y + GetCenter().y));
		p2.set((position->x + GetCenter().x) + 80, (position->y + GetCenter().y) - 80);
		p3.set((position->x + GetCenter().x) + 80, (position->y + GetCenter().y) + 80);*/

		/*p1.set((position->x), (position->y));
		p2.set((position->x) + 80, (position->y) - 80);
		p3.set((position->x) + 80, (position->y) + 80);*/
		CreateTriangle(vision, visionSize);
		CreateSquare(size);
		FillPoly(visionPath, vision, ofColor().gray);
		FillPoly(graphicsPath, graphics, ofColor().black);
		canRotate = false;
		
	}

	void Start() override {
		
	}

	void Update() override {
		CreateSquare(size.x);
		CreateTriangle(vision,100);

	}

	void LookAt(Vector2D target) {
		float newAng = MathUtils::GetAngle(*(this->position), target);
		angle = newAng;
		
	}

	void Draw() override {
	
		//if (angle > 360) angle = 0;

		
		ofPushMatrix();
			
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
				
				visionPath.draw();
				
			ofPopMatrix();
			
		ofPopMatrix();

		
	}

	

	bool CheckCollision() {
		
	}

	
};