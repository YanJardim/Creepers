#pragma once

#include "ofMain.h"
#include "Vector2D.h"
#include "Waypoint.h"
#include "Map.h"


using namespace math;

class WaypointManager {
private:
	
	vector<Waypoint> waypoints;
	Vector2D *target = nullptr, targetSize;
	Map map;

	const int detectRadius = 37;
	const int distanceBetweenPoints = 30;

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

		int limitX = 32, limitY = 24, limitXY = 40;
		int dX = 25, dY = 18;
		for (int i = 1; i <= limitX; i++) {
			waypoints.push_back(Waypoint(Vector2D(map.GetEnemyBase().x - distanceBetweenPoints * i, map.GetEnemyBase().y), target));
		}

		for (int i = 1; i <= limitY; i++) {
			waypoints.push_back(Waypoint(Vector2D(map.GetEnemyBase().x - distanceBetweenPoints * limitX, map.GetEnemyBase().y + distanceBetweenPoints * i), target));
		}

		for (int i = 1; i <= limitY; i++) {
			waypoints.push_back(Waypoint(Vector2D(map.GetEnemyBase().x, map.GetEnemyBase().y + distanceBetweenPoints * i), target));
		}

		for (int i = 1; i <= limitX; i++) {
			waypoints.push_back(Waypoint(Vector2D(map.GetEnemyBase().x - distanceBetweenPoints * i, map.GetEnemyBase().y + distanceBetweenPoints * limitY - 10), target));
		}

		for (int i = 2; i <= limitXY; i++) {
			waypoints.push_back(Waypoint(Vector2D(map.GetEnemyBase().x - dX * i, map.GetEnemyBase().y + dY * i), target));
		}


	}

	void Start(Vector2D *target, Map map) {
		this->target = target;
		this->map = map;
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

	void CheckMouseInside(Vector2D mouse) {
		for ( int i = 0; i < waypoints.size(); i++)
		{
			double d = MathUtils::GetDistance(waypoints[i].GetPosition(), mouse);
			int r = waypoints[i].GetSize() * waypoints[i].GetSize();
			if (d < r) {
				if (waypoints[i].GetBlock()) waypoints[i].SetBlock(false);
				else waypoints[i].SetBlock(true);
				
			}
		}
	}

	/*Waypoint GetNearWaypoint(Vector2D position) {
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
	}*/

	Waypoint GetNearWaypoint(Vector2D position) {
		int maxHeight = 9999;
		Waypoint target;
		for each (Waypoint a in waypoints)
		{
			double currentDist = MathUtils::GetDistance(position, a.GetPosition());
			if (a.GetHeight() <= maxHeight && currentDist < detectRadius)
			{
				maxHeight = a.GetHeight();
				target = a;

			}
		}
		return target;
	}

	void Clean() {
		delete target;
	}
	
};