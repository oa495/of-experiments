#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("open-sans.otf", 25);
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
    
    string str = "Messages and Means, Muriel Cooper at MIT";
    ofRectangle rect = font.getStringBoundingBox(str, 0, 0);
    int stringWidth = rect.getWidth();
    int stringNumCharacters = str.length();
    int radius = 100;
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    for (int n = 1; n < 8; n++) {
 
        int numberToDraw = (radius / stringWidth) * stringNumCharacters;
        cout << "test   " << numberToDraw << " , " << radius <<  " , "  << stringWidth << " , " << stringNumCharacters << endl;

        for (int i = 0; i < numberToDraw; i++) {
            
            string letter = ofToString(str[i % str.size()]);
            ofRectangle bb = font.getStringBoundingBox(letter, 0, 0);

            ofPushMatrix();
            
            angle = ofMap(i, 0, stringNumCharacters, 0, 360);
            // rotate around (0, 0)
            ofRotate(angle + increment);
            
            // Move up
            ofTranslate(0, radius + 50 * n);
            
            // center at (0, 0)
            ofTranslate(-bb.getWidth() / 2, bb.getHeight() / 2);
            
            font.drawString(letter, 0, 0);
            
            ofPopMatrix();
            
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
    cout << "test   " << x << " , " << y << endl;
    increment = ofMap(x, 0, ofGetWidth(), 0, 360);
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
