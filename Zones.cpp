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
    for(int i=1;i<=2;i++){
        for(int k=0;k<=2;k++){
            ofSetColor(200);
            ofLine(col[i].x,row[k].y,col[i].x,row[k].y+row[k].height*0.25);
            ofLine(col[i].x,row[k].y+row[k].height*0.75,col[i].x,row[k].y+row[k].height);
            ofSetColor(100);
            ofLine(col[k].x,row[i].y,col[k].x+col[k].width*0.25,row[i].y);
            ofLine(col[k].x+col[k].width*0.75,row[i].y,col[k].x+col[k].width,row[i].y);
        }
    }
}
