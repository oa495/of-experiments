#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}


//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    int width = ofGetWidth();
    int height = ofGetHeight();
    int distance = 100;
    int start = 50;
    int end = 550;
    vector<float> nums;  // create an empty vector of floats

    //ofLogNotice() << "width: " << width;
    //ofLogNotice() << "height: " << height;
    ofSetColor(255, 255, 255); //stroke color
    
    // circle sizes -> 2.5, 5, 10
    int smallCircle = 3;
    int mediumCircle = 7;
    int largeCircle = 7;
    int hugeCircle = 9;
    
//    float sinOfTime2 = sin( ofGetElapsedTimef() + PI);
//    float sinOfTimeMapped2 = ofMap(sinOfTime2, -1, 1, start, end);

    for (int i = 1; i < 10; i++){
        // vertical
        ofDrawLine(distance, start, distance, end);
        // horizontal
        ofDrawLine(start, distance, end, distance);
        distance+=50;
    }
    
    ofSetColor(255, 255, 255); //stroke color

    float sinOfTime = sin (ofGetElapsedTimef() * PI);
    float sinOfTime2 = sin (ofGetElapsedTimef() / 4 * PI);
    float sinOfTime3 = sin (2 * ofGetElapsedTimef() * PI);
    float mouseMap = ofMap(mouseX, 0, ofGetWidth(), 0, 360);
    float sinTimeMap = ofMap(sinOfTime2, -1, 1, smallCircle, hugeCircle);
    float sinTimeMap2 = ofMap(sinOfTime, -1, 1, 0, smallCircle);
    float sinTimeMap3 = ofMap(sinOfTime3, -1, 1, smallCircle, mediumCircle);

    // row 0
    ofDrawCircle(200, start, sinTimeMap2);
    ofDrawCircle(400, start, smallCircle);
    ofDrawCircle(300, start, mediumCircle);
    ofDrawCircle(300, start, sinTimeMap3);
    ofDrawCircle(350, start, mediumCircle);
    ofDrawCircle(250, start, sinTimeMap3);

    // row 1
    ofDrawCircle(450, 100, smallCircle);
    ofDrawCircle(250, 100, sinTimeMap);
    ofDrawCircle(300, 100, hugeCircle);
    ofDrawCircle(350, 100, hugeCircle);
    ofDrawCircle(400, 100, hugeCircle);
    ofDrawCircle(450, 100, mediumCircle);
    ofDrawCircle(500, 100, largeCircle);
    ofDrawCircle(200, 100, hugeCircle);
    
    // row 2
    ofDrawCircle(100, 150, mediumCircle);
    ofDrawCircle(150, 150, mediumCircle);
    ofDrawCircle(300, 150, mediumCircle);
    ofDrawCircle(500, 150, mediumCircle);
    ofDrawCircle(350, 150, largeCircle);
    ofDrawCircle(250, 150, largeCircle);
    ofDrawCircle(150, 150, hugeCircle);
    ofDrawCircle(200, 150, hugeCircle);
    ofDrawCircle(400, 150, hugeCircle);
    ofDrawCircle(450, 150, hugeCircle);

    
    // row 3
    ofDrawCircle(start, 200, sinTimeMap2);
    ofDrawCircle(350, 200, smallCircle);
    ofDrawCircle(end, 200, smallCircle);
    ofDrawCircle(250, 200, mediumCircle);
    ofDrawCircle(100, 200, largeCircle);
    ofDrawCircle(200, 200, largeCircle);
    ofDrawCircle(400, 200, largeCircle);
    ofDrawCircle(150, 200, hugeCircle);
    ofDrawCircle(450, 200, hugeCircle);

    // row 4
    ofDrawCircle(start, 250, smallCircle);
    ofDrawCircle(250, 250, smallCircle);
    ofDrawCircle(400, 250, sinTimeMap2);
    ofDrawCircle(450, 250, smallCircle);
    ofDrawCircle(500, 250, sinTimeMap2);
    ofDrawCircle(end, 250, smallCircle);
    ofDrawCircle(100, 250, largeCircle);
    ofDrawCircle(200, 250, largeCircle);
    ofDrawCircle(150, 250, hugeCircle);
    
    // row 5
    ofDrawCircle(start, 300, smallCircle);
    ofDrawCircle(250, 300, smallCircle);
    ofDrawCircle(100, 300, largeCircle);
    ofDrawCircle(200, 300, largeCircle);
    ofDrawCircle(150, 300, hugeCircle);


    // row 6
    ofDrawCircle(start, 350, smallCircle);
    ofDrawCircle(400, 350, smallCircle);
    ofDrawCircle(450, 350, smallCircle);
    ofDrawCircle(500, 350, smallCircle);
    ofDrawCircle(end, 350, smallCircle);
    ofDrawCircle(250, 350, smallCircle);
    ofDrawCircle(150, 350, hugeCircle);
    ofDrawCircle(100, 350, largeCircle);
    ofDrawCircle(200, 350, largeCircle);

    // row 7
    ofDrawCircle(350, 400, smallCircle);
    ofDrawCircle(start, 400, smallCircle);
    ofDrawCircle(end, 400, smallCircle);
    ofDrawCircle(250, 400, sinTimeMap3);
    ofDrawCircle(100, 400, largeCircle);
    ofDrawCircle(200, 400, largeCircle);
    ofDrawCircle(400, 400, largeCircle);
    ofDrawCircle(500, 400, largeCircle);
    ofDrawCircle(150, 400, hugeCircle);
    ofDrawCircle(450, 400, hugeCircle);

    // row 8
    ofDrawCircle(100, 450, mediumCircle);
    ofDrawCircle(150, 450, mediumCircle);
    ofDrawCircle(500, 450,  sinTimeMap3);
    ofDrawCircle(250, 450, largeCircle);
    ofDrawCircle(350, 450, sinTimeMap2);
    ofDrawCircle(150, 450, hugeCircle);
    ofDrawCircle(200, 450, hugeCircle);
    ofDrawCircle(400, 450, hugeCircle);
    ofDrawCircle(450, 450, hugeCircle);
    
    // row 9
    
    ofDrawCircle(300, 500, mediumCircle);
    ofDrawCircle(450, 500, mediumCircle);
    ofDrawCircle(200, 500, hugeCircle);
    ofDrawCircle(250, 500, hugeCircle);
    ofDrawCircle(300, 500, hugeCircle);
    ofDrawCircle(350, 500, hugeCircle);
    ofDrawCircle(400, 500, hugeCircle);

    // row 10
    ofDrawCircle(200, end, smallCircle);
    ofDrawCircle(400, end, smallCircle);
    ofDrawCircle(250, end, mediumCircle);
    ofDrawCircle(350, end, mediumCircle);
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
