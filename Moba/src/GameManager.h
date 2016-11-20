#pragma once


#define GMANAGER GameManager::GetInstance()
#include "Player.h"

enum gameState {
	MENU,
	PAUSE,
	GAME,
	GAMEOVER
};

class GameManager{
private:
	
	gameState state;
	Player *player;

public:
	static GameManager *instance;
	static GameManager* GetInstance()
	{
		if (!instance)
			instance = new GameManager;
		return instance;
	}
	GameManager() {
		
		

	}
	void Start(Player *player) {
		state = PAUSE;
		this->player = player;
	}

	void ChangeState(gameState newValue) {
		this->state = newValue;
	}
	gameState GetState() {
		return state;
	}

	bool CompareState(gameState compareValue) {
		if (state == compareValue)
			return true;

		return false;
	}

	void AlternatePause() {
		if (state == PAUSE)
			state = GAME;
		else state = PAUSE;
	}
};
