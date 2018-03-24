#include "ofApp.h"

void ofApp::setup(){
    img.load("us-flag.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    img.draw(0,0);
    
    ofTranslate(0, img.getHeight());
    
    for (int i = 0; i < img.getWidth(); i+=10){
        for (int j = 0; j < img.getHeight(); j+=10){
            ofColor pixel = img.getColor(i, j);
            int red = pixel.r;
            int green = pixel.g;
            int blue = pixel.b;
            float radius = 10;

            if (red == green && green == blue) {
                ofSetColor(255, 255, 255);
            }
            else if (red > green && red > blue) {
                ofSetColor(255, 0, 0);
            }
            else if (green > red && green > blue) {
                ofSetColor(0, 255, 0);
            }
            else {
                ofSetColor(0, 0, 255);
            }
            ofDrawCircle(i, j, radius);
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
