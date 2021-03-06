#include "ofMain.h"
#include "ofApp.h"
#include "WaypointManager.h"
#include "EnemyManager.h"
#include "GameManager.h"

WaypointManager *WaypointManager::instance = 0;
EnemyManager *EnemyManager::instance = 0;
GameManager *GameManager::instance = 0;

//========================================================================
int main( ){

	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
