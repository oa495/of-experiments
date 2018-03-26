#include "ofApp.h"


void ofApp::setup(){
    ofBackground(255);

    img.load("baby.png");
    
    cout << img.getWidth() << " " << img.getHeight() << endl;
    fbo.allocate(img.getWidth()*4, img.getHeight()*4, GL_RGBA, 4);
    gridSize = 2;
    
    // load all images
    for (int i = 0; i < 50; i++) {
        images[i].load(to_string(i+1) + ".jpg");
    }
    
    fbo.begin();
    ofClear(0, 0, 0, 255);
    ofSetColor(255);
    
    for(int i = 0; i < img.getWidth(); i+=gridSize) {
        vector<int> rowImg;
        for(int j = 0; j < img.getHeight(); j+=gridSize) {
            float brightness = 0;

            for (int m = 0; m < gridSize; m++) {
                for (int n = 0; n < gridSize; n++) {
                    brightness += img.getColor(m+i, n+j).getBrightness();
                }
            }
            
            brightness = brightness / (gridSize * gridSize);
            
            int idx = (int)ofMap(brightness, 0, 255, 0, 15);
            images[idx].draw(i*4, j*4, gridSize*4, gridSize*4);
            rowImg.push_back(idx);
        }
        // store the image at each index location, so what image is drawn at 1,1 etc
        imgArr.push_back(rowImg);
    }
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}


void ofApp::draw(){
    int width = ofGetWidth();
    int height = img.getHeight() / img.getWidth() * width;
    fbo.draw(0,0, width, height);
    int size = imgArr.size();
    // make sure mouse is within the bounds of the image and also that the index is imgArr
    if (mouseX < width && mouseY < height && mouseX < size && mouseY < size) {
        // pass the index of the image to the gui to draw
        gui->idx = imgArr[mouseX][mouseY];
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
