#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofEnableDepthTest();
	ofSetWindowTitle("Insta");
		
	this->icoSphere.setResolution(3);

	ofSetLineWidth(1);
	ofSetColor(ofColor(255));

	this->noise_value = ofRandom(10);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	ofRotateY(ofGetFrameNum() % 360);

	float tmp_noise_value = this->noise_value;

	for (int i = 300; i > 100; i -= 50)
	{
		this->icoSphere.setRadius(i);
		vector<ofMeshFace> triangles = icoSphere.getMesh().getUniqueFaces();
		for (int i = 0; i < triangles.size(); i++) {
			ofVec3f avg = (triangles[i].getVertex(0) + triangles[i].getVertex(1) + triangles[i].getVertex(2)) / 3;
			ofVec3f tmp = avg.normalized() * 300;
			float noise = ofNoise(tmp_noise_value, tmp.x * 0.0025, tmp.y * 0.0025, tmp.z * 0.0025);

			if (noise > 0.55) {
				ofMesh mesh;

				mesh.addVertex(triangles[i].getVertex(0));
				mesh.addVertex(triangles[i].getVertex(1));
				mesh.addVertex(triangles[i].getVertex(2));

				mesh.drawWireframe();

			}
		}

		tmp_noise_value += 0.025;
	}

	this->noise_value += 0.025;

	cam.end();
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
