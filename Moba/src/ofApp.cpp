#include "ofApp.h"
#include <future>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetEscapeQuitsApp(false);

	ofSetWindowTitle("Creepers");
	ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWindowWidth()/2, ofGetScreenHeight() / 2 - ofGetWindowHeight()/2);

	map = Map(0, 0, ofImage("Images/map.png"), "Map");
	player = Player(new Vector2D(map.GetBase()), 400, 1000, 20, "Player");
	
	WMANAGER->Start(new Vector2D(map.GetBase()), map);
	EMANAGER->Start(Vector2D(map.GetEnemyBase().x, map.GetEnemyBase().y), 2000, 100, 15, &player);
	GMANAGER->Start(&player);
	
	showWaypoints = false;
	
	SetupFonts();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (GMANAGER->CompareState(GAME)) {
		//EMANAGER->PrintAllEnemies();
		player.Update();
		player.UpdateBullets();
		WMANAGER->Update();
		EMANAGER->Update();

		EMANAGER->CheckCollision(&player);

		for each (Bullet* a in player.GetBullets())
		{
			EMANAGER->CheckCollision(a);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (GMANAGER->CompareState(GAME) || GMANAGER->CompareState(PAUSE)) {
		map.Draw();

		if (showWaypoints)
			WMANAGER->DrawWaypoints();

		EMANAGER->Draw();

		player.DrawBullets();
		player.Draw();

		enemyTextString = "Minions Speed: " + ofToString(EMANAGER->GetSpeed());
		enemySpawnTimeString = "Spawn Ratio: " + ofToString((float)EMANAGER->GetSpawnRatio() / 1000) + "s";


		enemySpawnTimeText.UpdateText(enemySpawnTimeString);
		enemySpawnTimeText.Draw();

		enemySpeedText.UpdateText(enemyTextString);
		enemySpeedText.Draw();
	}
	if (GMANAGER->CompareState(PAUSE)) {
		if (ofGetFrameNum() % 30 == 0)
			pauseText.SetColor(RandomColor());
		pauseText.Draw();
	}
	else if (GMANAGER->CompareState(MENU)) {
		menuText.Draw();
		menuLogo.Draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (GMANAGER->CompareState(GAME)) {
		if (key == 'i') {
			MathUtils::Alternate(showWaypoints);
		}

		if (key == '+') {
			EMANAGER->ChangeSpeed(EMANAGER->GetSpeed() + 10);
		}
		if (key == '-') {
			EMANAGER->ChangeSpeed(EMANAGER->GetSpeed() - 10);
		}

		

		if (key == 'a') {
			EMANAGER->SetSpawnRatio(EMANAGER->GetSpawnRatio() - 100);
		}

		if (key == 's') {
			EMANAGER->SetSpawnRatio(EMANAGER->GetSpawnRatio() + 100);
		}

		if (key == OF_KEY_CONTROL) {
			ctrlPressed = true;
		}
	}
	if (GMANAGER->CompareState(PAUSE) || GMANAGER->CompareState(GAME)) {
		if (key == OF_KEY_ESC) {
			GMANAGER->AlternatePause();
		}
	}
	else if (GMANAGER->CompareState(MENU)) {
		ofResetElapsedTimeCounter();
		GMANAGER->ChangeState(GAME);
	}

	
	

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(GMANAGER->CompareState(GAME)) {
		if (key == OF_KEY_CONTROL) {
			ctrlPressed = false;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(GMANAGER->CompareState(GAME)) {
		if (button == OF_MOUSE_BUTTON_3) {
			player.Move(Vector2D(x, y));

		}
		if (button == OF_MOUSE_BUTTON_2) {
			WMANAGER->CheckMouseInside(Vector2D(x, y));
		}

		if (button == OF_MOUSE_BUTTON_1 && ctrlPressed && showWaypoints) {
			WMANAGER->CreateWaypoint(Vector2D(x, y));
		}
		else if (button == OF_MOUSE_BUTTON_1) {
			player.Fire(Vector2D(x, y));
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::SetupFonts() {
	enemyTextString = "Minions Speed: " + ofToString(EMANAGER->GetSpeed());
	enemySpeedText = Text(enemyTextString, "Fonts/bebas.ttf", CENTER, ofColor().white, 270, 90, 12, "UI");

	enemySpawnTimeString = "Spawn  Ratio: " + ofToString(EMANAGER->GetSpawnRatio());
	enemySpawnTimeText = Text(enemyTextString, "Fonts/bebas.ttf", CENTER, ofColor().white, 140, 90, 12, "UI");

	menuText = Text("Press Any key to start!", "Fonts/Cornerstone.ttf", CENTER, ofColor().red, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 30, "MenuUI");
	menuLogo = Text("Creepers", "Fonts/bebas.ttf", CENTER, ofColor().black, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2 - 200, 30, "MenuUI");

	pauseText = Text("Paused!", "Fonts/Cornerstone.ttf", CENTER, ofColor().red, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 30, "PauseUI");
	
}

void ofApp::Clean() {
	EMANAGER->Clean();
	WMANAGER->Clean();
	player.Clean();
	map.Clean();
}

ofColor ofApp::RandomColor() {
	return ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

