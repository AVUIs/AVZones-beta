#include "Cursor.h"

void Cursor::setup(ofRectangle rect){
    x=rect.getCenter().x;
    y=rect.getCenter().y;
    w=rect.width;
    h=rect.height;
    rectX=rect.x;
    rectY=rect.y;
    fX=(x-rectX)/w;
    fY=(y-rectY)/h;
}

void Cursor::update(float posX, float posY){
    x=posX;
    y=posY;
    fX=(x-rectX)/w;
    fY=(y-rectY)/h;
}

void Cursor::draw(int color){
    float size=20;
    ofPushStyle();
    ofSetHexColor(color);
    ofLine(x-size,y,x+size,y);
    ofLine(x,y-size,x,y+size);
    ofPopStyle();
}