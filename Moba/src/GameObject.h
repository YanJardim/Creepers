#pragma once

#include "ofMain.h"
#include "Vector2D.h"


using namespace math;

 class GameObject {
protected:
	string tag;
	Vector2D *position = nullptr, size;

	ofPolyline graphics;
	ofImage image;

	bool alive;
public:

	GameObject() {};

	GameObject(Vector2D *position, Vector2D size) {
		this->position = position;
		this->size = size;
		this->tag = "Untagged";
		alive = true;

	}

	GameObject(Vector2D *position, Vector2D size, string tag) {
		this->position = position;
		this->size = size;
		this->tag = tag;
		alive = true;

	}
	GameObject(Vector2D *position, ofImage imagem, string tag) {
		this->position = position;
		this->image = image;
		this->tag = tag;
		alive = true;
	}
	~GameObject() {
		//delete(position);
	}

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;



	void FillPoly(ofPath &path, ofPolyline poly, ofColor color) {
		
		for (int i = 0; i < poly.getVertices().size(); i++)
		{

			if (i == 0) {
				path.newSubPath();
				path.moveTo(poly.getVertices()[i]);
			}
			else {
				path.lineTo(poly.getVertices()[i]);
			}
		}
		path.setColor(color);
		path.close();
		path.simplify();
	}
	void CreateSquare(int size) {
		this->size = Vector2D(size, size);
		graphics.clear();

		this->graphics.addVertex(position->x + size, position->y + size);
		this->graphics.addVertex(position->x + size, position->y - size);
		this->graphics.addVertex(position->x - size, position->y - size);
		this->graphics.addVertex(position->x - size, position->y + size);

		graphics.close();
	}
	void CreateSquare(int widht, int height) {
		this->size = Vector2D(widht, height);
		graphics.clear();

		this->graphics.addVertex(position->x + size.x, position->y + size.y);
		this->graphics.addVertex(position->x + size.x, position->y - size.y);
		this->graphics.addVertex(position->x - size.x, position->y - size.y);
		this->graphics.addVertex(position->x - size.x, position->y + size.y);

		graphics.close();
	}


	void CreateSquare(ofPolyline &poly, int size) {
		this->size = Vector2D(size, size);
		poly.clear();

		poly.addVertex(position->x + size, position->y + size);
		poly.addVertex(position->x + size, position->y - size);
		poly.addVertex(position->x - size, position->y - size);
		poly.addVertex(position->x - size, position->y + size);

		poly.close();
	}

	void CreateSquare(ofPolyline &poly, int width, int height) {
		//this->size = Vector2D(width, height);
		poly.clear();

		poly.addVertex(position->x + size.x, position->y + size.y);
		poly.addVertex(position->x + size.x, position->y - size.y);
		poly.addVertex(position->x - size.x, position->y - size.y);
		poly.addVertex(position->x - size.x, position->y + size.y);

		poly.close();
	}

	void CreateRotateSquare(ofPolyline &poly, int size) {
		this->size = Vector2D(size, size);
		poly.clear();

		poly.addVertex(+size, +size);
		poly.addVertex(+size, -size);
		poly.addVertex(-size, -size);
		poly.addVertex(-size, +size);

		poly.close();
	}

	void CreateTriangle(int size) {
		graphics.clear();
		this->graphics.addVertex(position->x + size * 2, position->y);
		this->graphics.addVertex(position->x + size, position->y + size);
		this->graphics.addVertex(position->x + size, position->y + (-size));
		this->graphics.close();
	}

	void CreateTriangle(ofPolyline &poly, int size) {
		poly.clear();
		poly.addVertex(position->x + size*2, position->y);
		poly.addVertex(position->x + size, position->y + size);
		poly.addVertex(position->x + size, position->y - size);
		poly.close();
	}

	void CreateRotateTriangle(ofPolyline &poly, int size) {
		poly.clear();
		poly.addVertex(size * 2, 0);
		poly.addVertex(size, + size);
		poly.addVertex(size, - size);
		poly.close();
	}



	void FillPolyClear(ofPath &path, ofPolyline poly, ofColor color) {
		path.clear();
		for (int i = 0; i < poly.getVertices().size(); i++)
		{

			if (i == 0) {
				path.newSubPath();
				path.moveTo(poly.getVertices()[i]);
			}
			else {
				path.lineTo(poly.getVertices()[i]);
			}
		}
		path.setColor(color);
		path.close();
		path.simplify();
	}

	void DrawImage(ofImage image) {
		image.draw(position->x, position->y);
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

	ofPolyline GetGraphics() {
		return graphics;
	}

	string GetTag() {
		return tag;
	}
	void SetTag(string newValue) {
		this->tag = newValue;
	}

	bool CompareTag(string tag1, string tag2) {
		if(tag1 == tag2)
			return true;

		return false;
	}

	bool CompareTag(string tag) {
		if (tag == this->tag)
			return true;

		return false;
	}

	bool IsAlive() {
		return alive;
	}

	void SetAlive(bool newValue) {
		alive = newValue;
	}

	void Clean(){
		delete position;
	}
	

};