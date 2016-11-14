#pragma once

#include "ofMain.h"
#include "Vector2D.h"

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
};