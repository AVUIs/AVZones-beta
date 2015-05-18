#pragma once

#include "ofMain.h"

class Cursor {
    
public:
    void setup(ofRectangle rect);
    void update(float posX, float posY);
    void draw(int color);
    
    float x, y;
    float w, h;
    float rectX, rectY;
    float fX, fY;
};