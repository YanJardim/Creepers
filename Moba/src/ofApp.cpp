#include "ofApp.h"
#include <future>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Creepers");
	ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWindowWidth()/2, ofGetScreenHeight() / 2 - ofGetWindowHeight()/2);

	map = Map(0, 0, ofImage("Images/map.png"), "Map");
	player = Player(new Vector2D(map.GetBase()), 400, 1000, 20, "Player");
	
	WMANAGER->Start(new Vector2D(map.GetBase()), map);
	EMANAGER->Start(Vector2D(map.GetEnemyBase().x, map.GetEnemyBase().y), 2000, 100, 15, &player);
	
	showWaypoints = false;
	

	enemyTextString = "Minions Speed: " + ofToString(EMANAGER->GetSpeed());
	enemySpeedText = Text(enemyTextString, "Fonts/bebas.ttf", CENTER, ofColor().white, ofGetWindowWidth()/2, 30, 12, "UI");

	enemySpawnTimeString = "Spawn  Ratio: " + ofToString(EMANAGER->GetSpawnRatio());
	enemySpawnTimeText = Text(enemyTextString, "Fonts/bebas.ttf", CENTER, ofColor().white, ofGetWindowWidth() / 2 - 140, 30, 12, "UI");

	
}

//--------------------------------------------------------------
void ofApp::update(){
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

//--------------------------------------------------------------
void ofApp::draw(){
	map.Draw();

	if(showWaypoints)
		WMANAGER->DrawWaypoints();

	EMANAGER->Draw();

	player.DrawBullets();
	player.Draw();
	
	enemyTextString = "Minions Speed: " + ofToString(EMANAGER->GetSpeed());
	enemySpawnTimeString = "Spawn Ratio: " + ofToString((float)EMANAGER->GetSpawnRatio() / 1000) + "s";

	if(ofGetFrameNum() % 50 == 0)
		enemySpeedText.SetColor(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));

	enemySpawnTimeText.UpdateText(enemySpawnTimeString);
	enemySpawnTimeText.Draw();

	enemySpeedText.UpdateText(enemyTextString);
	enemySpeedText.Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'i') {
		MathUtils::Alternate(showWaypoints);
	}

	if (key == '+') {
		EMANAGER->ChangeSpeed(EMANAGER->GetSpeed() + 10);
	}
	if (key == '-') {
		EMANAGER->ChangeSpeed(EMANAGER->GetSpeed() - 10);
	}

	if (key == OF_KEY_ESC) {
		EMANAGER->Clean();
		WMANAGER->Clean();
		player.Clean();
		map.Clean();
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

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_CONTROL) {
		ctrlPressed = false;
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

