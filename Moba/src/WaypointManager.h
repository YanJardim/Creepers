#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "Waypoint.h"



using namespace math;

class WaypointManager {
private:
	vector<Waypoint> waypoints;
	Vector2D target;

public:
	WaypointManager(Vector2D target) {
		this->target = target;
	}
	void AddWaypoints() {
		waypoints.push_back(Waypoint());
	}
	
};