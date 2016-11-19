#pragma once

#include "GameObject.h"
#include "MathUtils.h"
#include "Bullet.h"

using namespace math;

class Player : public GameObject{

private:
	Vector2D direction, velocity, mouse;
	int speed, bulletSpeed;
	bool target;
	ofPath path;

	vector<Bullet*> bullets;

public:
	Player() {
		this->target = false;
	}
	Player(int x, int y, int speed, int bulletSpeed,int size, string tag) : GameObject(new Vector2D(x, y), Vector2D(size, size), tag) {
		this->speed = speed;
		this->size = Vector2D(size, size);
		this->target = false;
		this->bulletSpeed = bulletSpeed;
		
		CreateSquare(size);
		FillPoly(path, graphics, ofColor().darkGray);
		this->velocity = Vector2D(0, 0);
	}
	Player(Vector2D *position, int speed, int bulletSpeed, int size, string tag) : GameObject(position, Vector2D(size, size), tag){
		this->speed = speed;
		this->target = false;
		this->bulletSpeed = bulletSpeed;
		
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

	Bullet* Fire(Vector2D mouse) {
		Bullet *a = new Bullet(position->x, position->y, bulletSpeed, new Vector2D(mouse), Vector2D(8, 2), "Bullet");
		a->Start();
		bullets.push_back(a);
		//cout << "A" << endl;
		PrintBullets();
		return a;
	}

	void DrawBullets() {
		for each (Bullet *a in bullets)
		{
			a->Draw();
			
		}
	}

	void UpdateBullets() {
		int index = 0;
		for each (Bullet *a in bullets)
		{
			a->Update();
			if (MathUtils::IsOutsideScreen(*(a->GetPosition()))) {
				bullets.erase(bullets.begin() + index);
				delete a;
				return;
			}
			index++;
		}

		
	}

	void PrintBullets() {
		cout << "-------------------------------------" << endl;
		for (int i = 0; i < bullets.size(); i++)
		{
			cout << i << ": " << *(bullets[i]->GetPosition())<< endl;
		}
		cout << "-------------------------------------" << endl;
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

	vector<Bullet*> GetBullets() {
		return bullets;
	}
	
	
};