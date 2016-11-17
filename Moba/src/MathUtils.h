#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "GameObject.h"

//class GameObject;

using namespace math;

class MathUtils {

private:


public:
	
	static double GetDistance(int x1, int y1, int x2, int y2) {
		int distancex = (x2 - x2) * (x2 - x1);
		int distancey = (y2 - y1) * (y2- y1);

		return sqrt(distancex + distancey);
		
	}
	static double GetDistance(Vector2D p1, Vector2D p2) {
		int distancex = (p2.x - p1.x) * (p2.x - p1.x);
		int distancey = (p2.y - p1.y) * (p2.y - p1.y);

		return sqrt(distancex + distancey);
	}

	static float GetAngle(Vector2D p1, Vector2D p2) {
		float a = atan2(p1.y - p2.y, p1.x - p2.x);
		return a * 180 / PI;
	}

	static Vector2D GetDirection(Vector2D p1, Vector2D p2) {
		return Vector2D(p2.x - p1.x, p2.y - p1.y);
	}

	static bool Alternate(bool &value) {
		if (value) { 
			value = false; 
			return false; 
		}
		else { 
			value = true; 
			return true; 
		}
	}
	static bool Alternate2(bool value) {
		if (value) {
			value = false;
			return false;
		}
		else {
			value = true;
			return true;
		}
	}

	static bool CheckCollision(GameObject *a, GameObject *b) {
		Vector2D bMinBounds = Vector2D(b->GetGraphics().getBoundingBox().getMinX(), b->GetGraphics().getBoundingBox().getMinY());
		Vector2D bMaxBounds = Vector2D(b->GetGraphics().getBoundingBox().getMaxX(), b->GetGraphics().getBoundingBox().getMaxY());


		
		for (int i = bMinBounds.y; i < bMaxBounds.y; i++) {
			for (int j = bMinBounds.x; j < bMaxBounds.x; j++) {
				//if((y > by1) && (y < by2) && (x > bx1) && (x < bx2)) {

					if (a->GetGraphics().inside(j, i)) {
						return true;
					}
				//}
			}
		}
		return false;
	}
};