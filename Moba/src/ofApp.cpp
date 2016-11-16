#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	map = Map(0, 0, ofImage("Images/map.png"), "Map");
	player = Player(new Vector2D(map.GetBase()), 200, 20, "Player");
	
	WMANAGER->Start(new Vector2D(map.GetBase()), map);
	EMANAGER->Start(map.GetEnemyBase(), 100, 10);

	
}

//--------------------------------------------------------------
void ofApp::update(){
	player.Update();
	WMANAGER->Update();
	EMANAGER->Update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	map.Draw();

	WMANAGER->DrawWaypoints();
	EMANAGER->Draw();
	
	player.Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	if (button == OF_MOUSE_BUTTON_1) {
		player.Move(Vector2D(x, y));
		
	}

	/*if (button == OF_MOUSE_BUTTON_3) {
		Vector2D target = Vector2D(x, y);
		EMANAGER->SetTargetAll(target);
	}*/
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
