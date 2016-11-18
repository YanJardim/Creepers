#pragma once

#define WMANAGER WaypointManager::GetInstance()
#define EMANAGER EnemyManager::GetInstance()

#include "Enemy.h"
#include "WaypointManager.h"
#include <memory>
#include <algorithm>


class EnemyManager{
private:
	vector<Enemy*> enemies;
	Vector2D spawnPosition;
	int spawnRatio;
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
	void Start(Vector2D spawnPosition,int spawnRatio, int speed, int size) {
		this->spawnPosition = spawnPosition;
		this->spawnRatio = spawnRatio;
		this->speed = speed;
		this->size = size;
		canSpawn = true;
		timer = 0;
	
	}
	void SpawnEnemy() {
		if (canSpawn) {
			int r = rand() % 3;

			Enemy *aux;
			if(r == 0)
				aux = new Enemy(new Vector2D(spawnPosition.x, spawnPosition.y), speed, size, "Enemy");
			else if (r == 1)
				aux = new Enemy(new Vector2D(spawnPosition.x-70, spawnPosition.y), speed, size, "Enemy");
			else if (r == 2)
				aux = new Enemy(new Vector2D(spawnPosition.x, spawnPosition.y+50), speed, size, "Enemy");

			enemies.push_back(aux);
		}

	}

	void SetTargetAll() {
		for each (Enemy *a in enemies)
		{
			Waypoint target = WMANAGER->GetNearWaypoint(*(a->GetPosition()));
			a->SetTarget(target);
			a->LookAt(target.GetPosition());
		}

		
	}

	void Draw() {
		for each (Enemy *a in enemies)
		{
			a->Draw();
		}

		
	
	}

	void Update() {
		//SetTargetAll();
		if (ofGetFrameNum()%spawnRatio == 0 && ofGetFrameNum() != 0) {
			SpawnEnemy();
			
		}
		for each (Enemy *a in enemies)
		{
			a->Update();
		}
		//cout << ofGetFrameNum() << endl;
	}

	bool CheckCollision(GameObject *other) {
		int index = 0;
		
			for each (Enemy *a in enemies)
			{
				if (MathUtils::GetDistance(*(a->GetPosition()), *(other->GetPosition())) < 80) {
					bool col = MathUtils::CheckCollision(a, other);
					if (col) {
						if (other->CompareTag("Bullet") ){
							enemies.erase(enemies.begin() + index);
							delete a;
						}

						return col;
					}
			}
			index++;
		}
		return false;
	}

	void CheckAlive() {
		int index = 0;
		for each (Enemy *a in enemies)
		{
			if(!a->IsAlive())
				enemies.erase(enemies.begin() + index);

			index++;
		}
	}

	void PrintAllEnemies() {
		if (enemies.size() != 0) {
			int index = 0;
			cout << "------------------------------------" << endl;
			for each (Enemy *a in enemies)
			{
				cout << index << ": " << *(a->GetPosition()) << endl;
				index++;
			}
			cout << "------------------------------------" << endl;
		}
	}

	void ChangeSpeed(int newValue) {
		this->speed = newValue;
		for each (Enemy *a in enemies)
		{
			a->SetSpeed(newValue);
		}
	}

	int GetSpeed() {
		return speed;
	}

	struct Deleter
	{
		void operator()(Enemy* obj) { delete obj; }
	};

	void Clean() {
		for_each(enemies.begin(), enemies.end(), Deleter());
	}
};
