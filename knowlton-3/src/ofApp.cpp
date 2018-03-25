#include "ofApp.h"

void ofApp::setup(){
    img.load("baby.png");
    
    cout << img.getWidth() << " " << img.getHeight() << endl;
    fbo.allocate(img.getWidth(), img.getHeight(), GL_RGBA);
    
    gridSize = 5;
    
    for (int i = 0; i < 50; i++) {
        images[i].load(to_string(i+1) + ".jpg");
    }
    
    fbo.begin();
    ofClear(0, 0, 0, 255);
    imgArr.clear();
    ofSetColor(255);
    
    for(int i = 0; i < img.getWidth(); i+=gridSize) {
        vector<ofImage> rowImg;
        for(int j = 0; j < img.getHeight(); j+=gridSize) {
            float brightness = 0;

            for (int m = 0; m < gridSize; m++) {
                for (int n = 0; n < gridSize; n++) {
                    brightness += img.getColor(m+i, n+j).getBrightness();
                }
            }
            
            brightness = brightness / (gridSize * gridSize);
            
            int idx = (int)ofMap(brightness, 0, 255, 0, 15);
            ofImage currentImg = images[idx];            
            currentImg.draw(i, j, gridSize, gridSize);
            rowImg.push_back(currentImg);
        }
    }
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.draw(0,0);
    if (mouseX < img.getWidth() && mouseY < img.getHeight()) {
        //imgArr[mouseX].draw(0, 0, 400, 400);
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
