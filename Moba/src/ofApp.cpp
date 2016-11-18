#include "ofApp.h"
#include <future>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Creepers");
	ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWindowWidth()/2, ofGetScreenHeight() / 2 - ofGetWindowHeight()/2);

	map = Map(0, 0, ofImage("Images/map.png"), "Map");
	player = Player(new Vector2D(map.GetBase()), 200, 20, "Player");
	
	WMANAGER->Start(new Vector2D(map.GetBase()), map);
	EMANAGER->Start(Vector2D(map.GetEnemyBase().x - 0, map.GetEnemyBase().y + 0), 200, 100, 10);
	
	showWaypoints = false;

	
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
	

	ofDrawBitmapString("Minions Speed: " + ofToString(EMANAGER->GetSpeed()), 15, 20);
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
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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

	if (button == OF_MOUSE_BUTTON_1) {
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

