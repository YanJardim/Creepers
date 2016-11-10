#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "Waypoint.h"



using namespace math;

class WaypointManager {
private:
	vector<Waypoint> waypoints;
	Vector2D *target;

public:
	WaypointManager() {

	}
	WaypointManager(Vector2D *target) {
		this->target = target;

		AddWaypoints();
	}
	void AddWaypoints() {
		waypoints.push_back(Waypoint(Vector2D(10, 10), target));
		waypoints.push_back(Waypoint(Vector2D(100, 10), target));
		waypoints.push_back(Waypoint(Vector2D(100, 100), target));
	}

	void Update(Vector2D *target) {
		for each (Waypoint a in waypoints)
		{
			//a.UpdateTarget(target);
			a.Update();
		}
	}
	void DrawWaypoints() {
		for each (Waypoint a in waypoints)
		{
			a.Draw();
		}
	}

	void PrintHeights() {
		cout << "-------------------------------------" << endl;
		for(int i =0; i < waypoints.size(); i++)
		{
			cout << i <<": "<<waypoints[i].GetHeight() << endl;
		}
		cout << "-------------------------------------" << endl;
	}
	
};