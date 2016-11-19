#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "ofxCenteredTrueTypeFont.h"

using namespace math;

enum pivot {
	CENTER,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Text : public GameObject{
private:
	string text;
	ofxCenteredTrueTypeFont font;
	pivot alignment;
	ofColor color;
public:
	Text() {};

	Text(string text, string fontPath, pivot alignment, ofColor color, int x, int y, int size ,string tag) : GameObject(new Vector2D(x, y), Vector2D(size, size), tag) {
		this->text = text;
		this->font.load(fontPath, size);
		this->alignment = alignment;
		this->color = color;
	}


	// Inherited via GameObject
	void Start() override {

	}
	void Update() override {

	}
	void Draw() override {
		DrawFont();
		
	}

	Vector2D GetTextSize(){
		return Vector2D(font.getStringBoundingBox(text, 0, 0).x, font.getStringBoundingBox(text, 0, 0).y);
	}

	void DrawFont() {
		ofSetColor(color);
		switch (alignment)
		{
			
		case CENTER:
		
			font.drawStringCentered(text, position->x, position->y);
			break;
		case LEFT:
			font.drawString(text, position->x, position->y);
			break;
		case RIGHT:
			font.drawString(text, position->x + GetTextSize().x, position->y);
			break;
		case UP:
			font.drawString(text, position->x - GetTextSize().x/2, position->y);
			break;

		case DOWN:
			font.drawString(text, position->x - GetTextSize().x / 2, position->y - GetTextSize().y);
			break;

		
		}

		ofSetColor(ofColor().white);
		
	}

	void UpdateText(string newValue) {
		this->text = newValue;
	}

	void SetAlignment(pivot newValue) {
		this->alignment = newValue;
	}

	void SetColor(ofColor newValue) {
		this->color = newValue;
	}
	

};