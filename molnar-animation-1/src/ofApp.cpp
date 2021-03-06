#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(500, 500);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------

void ofApp::drawRect( float x, float y, float width, float height  ){
    float sinOfTime2 = sin( ofGetElapsedTimef() + PI);
    float sinOfTimeMapped2 = ofMap(sinOfTime2, -1, 1, y-height/2, y+height/2);
    float sinOfTimeMapped3 = ofMap(sinOfTime2, -1, 1, x-width/2, x+width/2 );

    ofDrawLine(x-width/2, y-height/2, sinOfTimeMapped3, y-height/2);
    ofDrawLine(sinOfTimeMapped3, y+height/2, x+width/2, y+height/2);

    ofDrawLine(x-width/2, sinOfTimeMapped2, x-width/2, y+height/2);
    ofDrawLine(x+width/2, y-height/2, x+width/2, sinOfTimeMapped2);
}

void ofApp::draw(){
    ofBackground(255);
    ofFill();
    ofSetColor(255, 255, 255); //fill color
    ofNoFill();
    ofSetColor(0, 0, 0); //stroke color
    
    int step = 100;
    for (int row = 0; row < 5; row++){
        for (int col = 0; col < 5; col++) {
            int rowVal = row*step + step/2;
            int colVal = col*step + step/2;
            drawRect(rowVal, colVal, step, step);
            for (int count = 0; count < 10; count++) {
                step = 100 - count * 10;
                drawRect(rowVal, colVal, step, step);
            }
            step = 100;
            rowVal = row*step;
            colVal = col*step;
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
