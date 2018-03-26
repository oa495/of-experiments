/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"

void GuiApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(false);
    
    for (int i = 0; i < 50; i++) {
        images[i].load(to_string(i+1) + ".jpg");
    }
}

void GuiApp::update(){
    
}

void GuiApp::draw(){
    ofImage img = images[idx];
    img.draw(0, 0, ofGetWidth(), ofGetHeight());
    gui.draw();
}
