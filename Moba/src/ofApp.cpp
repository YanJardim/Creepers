#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	p = Player(500, 500, 200, 20, "Player");
	WMANAGER->Start(new Vector2D(ofGetWindowSize().x, ofGetWindowSize().y/2), p.GetCenter());
	EMANAGER->Start(Vector2D(0.f, ofGetWindowSize().y / 2));

	
}

//--------------------------------------------------------------
void ofApp::update(){
	p.Update();
	WMANAGER->Update();
	EMANAGER->Update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	WMANAGER->DrawWaypoints();
	EMANAGER->Draw();

	p.Draw();
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
		p.Move(Vector2D(x, y));
		
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
