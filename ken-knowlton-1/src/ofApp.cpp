#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.setup(640,480);
}

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
}

//--------------------------------------------------------------


bool compare(vector<ofColor> a, vector<ofColor> b) {
    return a[0].getSaturation() < b[0].getSaturation();
}

void ofApp::draw(){

    ofBackground(0);
    
    brightness.clear();
    pixels.clear();
    
    for (int i = 0; i < grabber.getWidth(); i+=10){
        vector<float> rowBrightness;
        vector<ofColor> rowPixels;
        for (int j = 0; j < grabber.getHeight(); j+=10){
            ofColor pixel = grabber.getPixels().getColor(i,j);
            rowPixels.push_back(pixel);
            rowBrightness.push_back(pixel.getBrightness());
        }
        brightness.push_back(rowBrightness);
        pixels.push_back(rowPixels);
        rowBrightness.clear();
    }
    
    for( int i = 0; i < pixels.size(); i++){
        cout << pixels[i][i] << endl;
    }
    
   // ofSort(pixels, compare);

    for (int i = 0; i < grabber.getWidth(); i+=10) {
        for (int j = 0; j < grabber.getHeight(); j+=10){
            ofSetColor(pixels[i/10][j/10]);
            ofDrawRectangle(i, j, 10, 10);
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
