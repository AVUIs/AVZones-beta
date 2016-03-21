#include "Pattern.h"

void Pattern::setup(float x, float width){
    counter = 0;
    colX = x;
    colW = width;
    patInfo.clear();
}

void Pattern::update(){
    counter++;
    if(counter==120) counter=0;
    for(int i=0;i<patInfo.size();i++){
        if(counter==patInfo[i].time){
            patInfo[i].playing=true;
            //printf("hit %i ,",counter);
        }else{
            patInfo[i].playing=false;
        }
    }
}

void Pattern::draw(){
    for(int i=0;i<patInfo.size();i++){
        float timeX = ofMap(patInfo[i].time,0,119,colX,colX+colW);
        float radius;
        if(patInfo[i].playing){
            ofSetColor(255,200);
             radius = 200;
        }else{
            ofSetColor(127);
             radius = 20;
        }
        ofFill();
        ofCircle(patInfo[i].x, patInfo[i].y,radius);
        ofNoFill();
        ofRect(timeX-radius/2, ofGetHeight()/2-radius, radius,radius*2);
        //ofLine(timeX-radius, ofGetHeight()/2, timeX+radius, ofGetHeight()/2);
        //ofLine(timeX, ofGetHeight()/2-radius, timeX, ofGetHeight()/2+radius);
        ofLine(patInfo[i].x, patInfo[i].y, timeX, ofGetHeight()/2);

    }
}

void Pattern::add(int myX,int myY,int myTime, float myColX){
    patInfo.push_back(touchInfo());
    patInfo[patInfo.size()-1].x=myX;
    patInfo[patInfo.size()-1].y=myY;
    patInfo[patInfo.size()-1].time=myTime;
    patInfo[patInfo.size()-1].playing=false;
}