#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	p = Player(500, 500, 200);
	wManager = WaypointManager(p.GetPosition(), p.GetCenter());
}

//--------------------------------------------------------------
void ofApp::update(){
	p.Update();
	wManager.Update(p.GetPosition());
	//wManager.PrintHeights();
}

//--------------------------------------------------------------
void ofApp::draw(){
	p.Draw();
	wManager.DrawWaypoints();
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
	if(button == 0)
		p.Move(Vector2D(x, y));
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
