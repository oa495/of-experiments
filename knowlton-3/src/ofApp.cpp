#include "ofApp.h"

bool sort_brightness(ofImage a, ofImage b) {
    float aBrightness = 0;
    float bBrightness = 0;

    for (int m = 0; m < a.getWidth(); m++) {
        for (int n = 0; n < a.getHeight(); n++) {
            aBrightness += a.getColor(m, n).getBrightness();
        }
    }
    
    aBrightness = aBrightness / (a.getWidth()*a.getHeight());
    
    for (int m = 0; m < b.getWidth(); m++) {
        for (int n = 0; n < b.getHeight(); n++) {
            bBrightness += b.getColor(m, n).getBrightness();
        }
    }
    bBrightness = bBrightness/ (b.getWidth()*b.getHeight());
    
    return aBrightness < bBrightness;
}

bool sort_lightness(ofImage a, ofImage b) {
    float aLightness = 0;
    float bLightness = 0;
    
    for (int m = 0; m < a.getWidth(); m++) {
        for (int n = 0; n < a.getHeight(); n++) {
            aLightness += a.getColor(m, n).getLightness();
        }
    }
    
    aLightness = aLightness / (a.getWidth()*a.getHeight());
    
    for (int m = 0; m < b.getWidth(); m++) {
        for (int n = 0; n < b.getHeight(); n++) {
            bLightness += b.getColor(m, n).getLightness();
        }
    }
    bLightness = bLightness/ (b.getWidth()*b.getHeight());
    
    return aLightness < bLightness;
}

void ofApp::setup(){
    ofBackground(255);

    img.load("baby-s.png");
    
    cout << img.getWidth() << " " << img.getHeight() << endl;
    fbo.allocate(img.getWidth()*6, img.getHeight()*6, GL_RGBA, 4);
    gridSize = 2;
    
    // load all images
    for (int i = 0; i < 50; i++) {
        ofImage temp;
        temp.load(to_string(i+1) + ".jpg");
        images.push_back(temp);
    }
    
    ofSort(images, sort_brightness);
    
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
            
            int idx = (int)ofMap(brightness, 0, 255, 0, 49);
            images[idx].draw(i*6, j*6, gridSize*6, gridSize*6);
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
    int width2 = imgArr.size();
    int height2 = imgArr[0].size();
    int newMouseX = ofMap(mouseX, 0, width, 0, width2);
    int newMouseY = ofMap(mouseY, 0, height, 0, height2);

    cout << newMouseX << " " << newMouseY << endl;

    // make sure mouse is within the bounds of the image and also that the index is imgArr
    if (mouseX >= 0 && mouseX < width && mouseY >= 0 && mouseY < height) {
        // pass the index of the image to the gui to draw
        int idx = imgArr[newMouseX][newMouseY];
        if (idx <= 50) {
            cout << idx << endl;
            gui->idx = idx;
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
