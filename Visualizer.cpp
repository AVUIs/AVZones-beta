#include "Visualizer.h"

void Visualizer::setup(int bufferSize, ofRectangle rect){
    myBufferSize=bufferSize;
    posX = rect.x;
    posY = rect.y;
    width = rect.width;
    height = rect.height;
    red=ofMap(rect.x,0,ofGetWidth()-rect.width,0,127);
    fullscreen=false;
}

void Visualizer::update(){
}

void Visualizer::draw(float * buffer, float amplitude){
    //wave
    ofPushStyle();
    ofFill();
    ofSetColor(red,0,255, amplitude*255);
    //ofSetLineWidth(1);
    float y1 = ofGetHeight() * 0.5;
    for(int i=0; i<myBufferSize; i++){
        float p = i / (float)(myBufferSize);
        float y2 = buffer[i] * (height);
        if(fullscreen){
            float x = p * ofGetWidth();
            float rectWidth=ofGetWidth()/myBufferSize;
            ofRect(x, posY+y1,rectWidth,posY+y2);
        }else{
            float x = p * width;
            float rectWidth=width/myBufferSize;
            ofRect(posX+x, posY+y1,rectWidth,posY+y2);
        }
    }
    ofPopStyle();
}
