#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("share-tech.otf", 25);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofNoFill();
    ofSetColor(255);
    ofFill();
    ofSetColor(255);
    ofEnableDepthTest();

    string str = "Messages and Means, Muriel Cooper at MIT";
    ofRectangle rect = font.getStringBoundingBox(str, 0, 0);
    float stringWidth = rect.getWidth();
    int stringNumCharacters = str.length();
    float radius = 100;
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int n = 1; n < 10; n++) {
        int numberToDraw = 6 * (float(radius) / float(stringWidth)) * stringNumCharacters;
        cam.begin();
    
        for (int i = 0; i < numberToDraw; i++) {
            int half = numberToDraw / 2;
            if (i >= half && size > 180) {
                ofRotateX(size);
            }
            else {
                ofRotateZ(0);
            }
            string letter = ofToString(str[i % str.length()-1]);
            ofRectangle bb = font.getStringBoundingBox(letter, 0, 0);
            ofPushMatrix();
            angle = ofMap(i, 0, numberToDraw, 0, 360);
            // rotate around (0, 0)
            ofRotate(-angle + increment * n);
            // Move up
            ofTranslate(0, radius);
            // center at (0, 0)
            ofTranslate(-bb.getWidth() / 2, bb.getHeight() / 2);
            font.drawString(letter, 0, 0);
            ofPopMatrix();

        }
        radius = radius + 50;
        cam.end();

        
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
    cout << "test   " << x << " , " << y << endl;
    float sinOfTime2 = sin( x + PI);
    increment = ofMap(sinOfTime2, -1, 1, 0, 360);
    size = ofMap(y, 0, ofGetHeight(), 0, 360);
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
