#include "Zones.h"

void Zones::setup(){
    screenW=ofGetHeight();
    screenH=ofGetWidth();
    
    for(int a=0; a<3; a++){
        col[a]=ofRectangle(screenW/3*a,0,screenW/3,screenH);
        for(int b=0; b<3; b++){
            row[b]=ofRectangle(0,screenH/3*b,screenW,screenH/3);
            rects[a][b]=ofRectangle(col[a].x,row[b].y,col[a].width,row[b].height);
        }
    }
}

void Zones::draw(){
    ofSetColor(200);
    ofLine(col[1].x,0,col[1].x,screenH);
    ofLine(col[2].x,0,col[2].x,screenH);
    ofSetColor(100);
    ofLine(0,row[1].y,screenW,row[1].y);
    ofLine(0,row[2].y,screenW,row[2].y);
}
