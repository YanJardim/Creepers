#pragma once

#include "ofMain.h"

#include "Player.h"
#include "Map.h"
#include "Text.h"

#include "EnemyManager.h"
#include "GameManager.h"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void SetupFonts();
		void Clean();
		ofColor RandomColor();

		Player player;
		Map map;

		bool showWaypoints, ctrlPressed;

		Text enemySpeedText;
		string enemyTextString;

		Text enemySpawnTimeText;
		string enemySpawnTimeString;

		Text scoreText;
		string scoreString;

		Text menuText, menuLogo, pauseText;
		Text gameOverText;


		
};
