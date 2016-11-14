#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "MathUtils.h"

using namespace math;

 class GameObject {
protected:

	Vector2D *position, size;

	ofPolyline graphics;
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
		//ofDrawRectangle(position->x, position->y, size.x, size.y);
		//graphics.draw();
	}



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

	void CreateSquare(ofPolyline &poly, int size) {
		this->size = Vector2D(size, size);
		poly.clear();

		poly.addVertex(position->x + size, position->y + size);
		poly.addVertex(position->x + size, position->y - size);
		poly.addVertex(position->x - size, position->y - size);
		poly.addVertex(position->x - size, position->y + size);

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

	

};