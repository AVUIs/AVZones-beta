#pragma once

#include "ofMain.h"
//#include "ofxiOS.h"
//#include "ofxiOSExtras.h"
//#include "ofxMaxim.h"

class Visualizer {
    
public:
    void setup(int bufferSize, ofRectangle rect);
    void update();
    void draw(float * buffer, float amplitude);
    
    int myBufferSize;
    int red;
    float posX, posY, width, height;
    bool fullscreen;
    
};