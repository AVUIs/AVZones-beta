#pragma once

#include "ofMain.h"

class Zones {
    
public:
    void setup();
    void draw();
    float screenW, screenH;
    ofRectangle rects[3][3];
    ofRectangle row[3];
    ofRectangle col[3];
};