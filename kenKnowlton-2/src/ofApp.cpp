#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int width = ofGetWidth();
    int height = ofGetHeight();
    grabber.setup(width, height);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    int width = grabber.getWidth();
    int height = grabber.getHeight();

    ofRectangle rect1, rect2, rect3;
    int yIncrement = ofMap(mouseY, 0, height, 0, 100);
    int xIncrement = ofMap(mouseX, 0, height, 0, 100);

    rect1.x = width/3-100 + xIncrement;
    rect1.y = (height/3)-150 + yIncrement;
    rect1.width = 200;
    rect1.height = 100;
    
    rect2.x = width/3 + xIncrement;
    rect2.y = height/3 + yIncrement;
    rect2.width = 250;
    rect2.height = 250;
    
    rect3.x = width/2+100 + xIncrement;
    rect3.y = (height/3)+150 + yIncrement;
    rect3.width = 200;
    rect3.height = 100;
    
    ofDrawRectangle(rect1);
    ofDrawRectangle(rect2);
    ofDrawRectangle(rect3);
    
    for (int i = 0; i < grabber.getWidth(); i+=10){
        for (int j = 0; j < grabber.getHeight(); j+=10){
            ofColor pixel = grabber.getPixels().getColor(i,j);
            if (ofRectangle(rect1).inside(i, j) || ofRectangle(rect2).inside(i, j) || ofRectangle(rect3).inside(i, j) ) {
                ofSetColor(pixel);
                ofDrawRectangle(i, j, 10, 10);
            }
        }
    }

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
