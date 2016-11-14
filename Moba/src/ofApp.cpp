#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	p = Player(500, 500, 200, 50);
	wManager = WaypointManager(p.GetPosition(), p.GetCenter());
	e1 = Enemy(new Vector2D(200, 200), 100, 70);
}

//--------------------------------------------------------------
void ofApp::update(){
	p.Update();
	wManager.Update();
	e1.Update();
	e1.LookAt(*(p.GetPosition()));
	//wManager.PrintHeights();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	wManager.DrawWaypoints();
	e1.Draw();

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
	if (button == 0) {
		p.Move(Vector2D(x, y));
		
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
