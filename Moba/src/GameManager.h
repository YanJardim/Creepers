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
	int score;

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
		state = MENU;
		this->player = player;
		this->score = 0;
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
		if (state == GAME)
			state = PAUSE;
		else if (state == PAUSE)
			state = GAME;
		
	}

	void AddScore(int amount) {
		score += amount;
	}

	int GetScore() {
		return score;
	}
};
