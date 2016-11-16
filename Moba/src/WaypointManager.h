#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "Waypoint.h"



using namespace math;

class WaypointManager {
private:
	
	vector<Waypoint> waypoints;
	Vector2D *target = nullptr, targetSize;

public:
	static WaypointManager *instance;
	static WaypointManager* GetInstance()
	{
		if (!instance)
			instance = new WaypointManager;
		return instance;
	}

	WaypointManager() {

	}
	WaypointManager(Vector2D *target, Vector2D targetSize) {
		this->target = target;
		this->targetSize = targetSize;
		AddWaypoints();
	}
	void AddWaypoints() {
		waypoints.push_back(Waypoint(Vector2D(100, 50), target, targetSize));
		waypoints.push_back(Waypoint(Vector2D(200, 50), target, targetSize));
		waypoints.push_back(Waypoint(Vector2D(300, 60), target, targetSize));
		waypoints.push_back(Waypoint(Vector2D(400, 80), target, targetSize));
	}

	void Start(Vector2D *target, Vector2D targetSize) {
		this->target = target;
		this->targetSize = targetSize;
		AddWaypoints();
	}

	void Update() {
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

	Waypoint GetNearWaypoint(Vector2D position) {
		double minDist = 9999;
		Waypoint target;
		for each (Waypoint a in waypoints)
		{
			double currentDist = MathUtils::GetDistance(position, a.GetPosition());
			if (minDist > currentDist) {
				minDist = currentDist;
				target = a;
			}
		}
		return target;
	}

	/*Waypoint GetNearWaypoint(Vector2D position) {
		int maxHeight = 9999;
		Waypoint target;
		for each (Waypoint a in waypoints)
		{
			double currentDist = MathUtils::GetDistance(position, a.GetPosition());
			if (a.GetHeight() <= maxHeight && currentDist < 50)
			{
				maxHeight = a.GetHeight();
				target = a;

			}
		}
		return target;
	}*/
	
};