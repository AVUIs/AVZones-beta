#pragma once

#include "ofMain.h"

class Pattern {
    
public:
    void setup(float x, float width);
    void update();
    void draw();
    void add(int myX, int myY, int myTime, float myColX);
    
    int counter;
    float colX, colW;
    
    struct touchInfo {
        int x;
        int y;
        int time;
        bool playing;
    } ;
    vector<touchInfo> patInfo;
};