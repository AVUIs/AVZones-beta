#pragma once

#include "ofMain.h"
#include "Playlist.h"

class Selector {
    
public:
    void setup(ofRectangle rect, int index);
    void draw();
    
    ofTrueTypeFont font;
    ofRectangle rects[9];
    Playlist list;
    bool selecting;
    int selected;
    int myIndex;
};