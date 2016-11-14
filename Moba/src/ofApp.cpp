#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	p = Player(500, 500, 200, 20);
	//wManager = WaypointManager(new Vector2D(ofGetWindowSize().x/2, ofGetWindowSize().y), p.GetCenter());
	WMANAGER->Start(new Vector2D(ofGetWindowSize().x, ofGetWindowSize().y/2), p.GetCenter());
	EMANAGER->Start(Vector2D(0.f, ofGetWindowSize().y / 2));
	//e1 = Enemy(new Vector2D(200, 200), 100, 20);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	p.Update();
	//wManager.Update();
	WMANAGER->Update();
	EMANAGER->Update();
	//e1.Update();
	
	//wManager.PrintHeights();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//wManager.DrawWaypoints();
	//WaypointManager::GetInstance()->Update();
	WMANAGER->DrawWaypoints();
	EMANAGER->Draw();
	//e1.Draw();

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
