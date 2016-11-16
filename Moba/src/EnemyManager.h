#pragma once

#define WMANAGER WaypointManager::GetInstance()
#define EMANAGER EnemyManager::GetInstance()

#include "Enemy.h"
#include "WaypointManager.h"


class EnemyManager {
private:
	vector<Enemy*> enemys;
	Vector2D spawnPosition;

	bool canSpawn;
	int timer;

	int speed = 100, size = 20;

public:
	static EnemyManager *instance;
	static EnemyManager* GetInstance()
	{
		if (!instance)
			instance = new EnemyManager;
		return instance;
	}
	EnemyManager() {
		
		canSpawn = true;

	}
	void Start(Vector2D spawnPosition, int speed, int size) {
		this->spawnPosition = spawnPosition;
		this->speed = speed;
		this->size = size;
		canSpawn = true;
		timer = 0;
	
	}
	void SpawnEnemy() {
		if (canSpawn) {
			Enemy *aux = new Enemy(new Vector2D(spawnPosition.x, spawnPosition.y), speed, size, "Enemy");
			enemys.push_back(aux);
		}

	}

	void SetTargetAll() {
		for each (Enemy *a in enemys)
		{
			Waypoint target = WMANAGER->GetNearWaypoint(*(a->GetPosition()));
			a->SetTarget(target);
			a->LookAt(target.GetPosition());
		}

		
	}

	void Draw() {
		for each (Enemy *a in enemys)
		{
			a->Draw();
		}
	
	}

	void Update() {
		//SetTargetAll();
		if (ofGetFrameNum()%100 == 0) {
			SpawnEnemy();
			
		}
		for each (Enemy *a in enemys)
		{
			a->Update();
		}
		//cout << ofGetFrameNum() << endl;
	}

	

	
};