#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    //Environment
    ofSetFrameRate(60);
    ofSetOrientation(OF_ORIENTATION_90_RIGHT);
    ofSetCircleResolution(200);
    ofEnableSmoothing();
    ofBackground(0);
    ofSetLineWidth(3);
    //other setups
    bufferSize=512;
    zone.setup();
    for(int i=0; i<3; i++){
        delCursor[i].setup(zone.rects[i][0]);
        samCursor[i].setup(zone.rects[i][1]);
        filCursor[i].setup(zone.rects[i][2]);
        sel[i].setup(zone.col[i],i);
        sam[i].setup(bufferSize, i);
        viz[i].setup(bufferSize,zone.col[i]);
    }
    ofSoundStreamSetup(2,2,this, 44100, bufferSize, 4);
}
//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<3; i++){
        if(sam[i].recording){
            pat[i].update();
            //printf("%i, ", pat[i].counter);
            for(int p=0;p<pat[i].patInfo.size();p++){
                if(pat[i].patInfo[p].playing) sam[i].trigger(pat[i].patInfo[p].x,pat[i].patInfo[p].y, i);
            }
        }
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    for(int i=0; i<3; i++){
        viz[i].draw(sam[i].buffer,float(sam[i].amplitude));
        (sam[i].delayOn)? delCursor[i].draw(0x33FF33) : delCursor[i].draw(0xFF3333);
        (sam[i].filterOn)? filCursor[i].draw(0x33FF33) : filCursor[i].draw(0xFF3333);
        (sam[i].looping)? samCursor[i].draw(0x33FF33) : samCursor[i].draw(0xFF3333);
        if(sel[i].selecting) sel[i].draw();

        if(sam[i].recording){
            //dots
            pat[i].draw();
            //reading line
            float lineX=ofMap(pat[i].counter,0,119,zone.col[i].x,zone.col[i].x+zone.col[i].width);
            //printf("c %i ,",pat[i].counter);
            ofSetColor(255);
            ofLine(lineX,0,lineX,ofGetHeight());
            ofSetColor(255,0,0);
            //red frame
            ofRect(zone.rects[i][1]);
        }
    }
    zone.draw();
    ofFill();
    for(int k=0; k<touches.size(); k++){
        ofSetColor(255);
        ofCircle(touches[k], 50);
    }
};
//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    for (int i = 0; i < bufferSize; i++){
        sam[0].play(i, 0.25);
        sam[1].play(i, 0.5);
        sam[2].play(i, 0.75);
        output[i*nChannels    ]=0;
        output[i*nChannels + 1]=0;
        for(int k=0; k<3; k++){
            output[i*nChannels    ] += sam[k].outputs[0];//left output
            output[i*nChannels + 1] += sam[k].outputs[1];//right output
        }
    }
}
//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){}
//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
    touches.push_back(ofPoint(touch.x,touch.y));
    for(int i=0; i<3; i++){
        if(touches.size()==2){
            //double touch
            
            //filter
            if(zone.rects[i][2].inside(touch.x, touch.y))
                (sam[i].filterOn)? sam[i].filterOn = false : sam[i].filterOn = true;
            
            //delay
            if(zone.rects[i][0].inside(touch.x, touch.y))
                (sam[i].delayOn)? sam[i].delayOn = false : sam[i].delayOn = true;
            
            //loop
            if(zone.rects[i][1].inside(touches[0])&&zone.rects[i][1].inside(touches[1]))
                (sam[i].looping)? sam[i].looping=false : sam[i].looping = true;
            
            
        }
        //if(touches.size()==3)
            //(ofGetOrientation()==OF_ORIENTATION_90_RIGHT)? ofSetOrientation(OF_ORIENTATION_DEFAULT) : ofSetOrientation(OF_ORIENTATION_90_RIGHT);
            //if(zone.rects[i][2].inside(touches[0])&&zone.rects[i][2].inside(touches[1]))//triple touch
                //(viz[i].fullscreen)? viz[i].fullscreen=false : viz[i].fullscreen = true;
        
        //single touch
        if(!sel[i].selecting){
            if(zone.rects[i][1].inside(touch.x, touch.y)){
                sam[i].trigger(touch.x,touch.y, i);
                samCursor[i].update(touch.x,touch.y);
                sam[i].touched=true;
                if(sam[i].recording) pat[i].add(touch.x, touch.y, pat[i].counter, zone.col[i].x);
            }
        }
    }
}
//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){
    for(int i=0; i<3; i++){
        if(zone.rects[i][0].inside(touch.x, touch.y)){
            delCursor[i].update(touch.x,touch.y);
            sam[i].delay(delCursor[i].fX,delCursor[i].fY);
        }
        if(zone.rects[i][2].inside(touch.x, touch.y)){
            filCursor[i].update(touch.x,touch.y);
            sam[i].filter(filCursor[i].fX,filCursor[i].fY);
        }
    }
    for(int k=0; k<touches.size(); k++){
        touches[k].x=touch.x;
        touches[k].y=touch.y;
    }

}
//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){
    touches.erase(touches.begin()+touch.id);
    for(int i=0; i<3; i++){
        if(zone.rects[i][1].inside(touch.x, touch.y)){
            sam[i].touched=false;
        }
    }
}
//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){
    for(int i=0; i<3; i++){
        if(sel[i].selecting){
            for(int k=0; k<9; k++){
                if(sel[i].rects[k].inside(touch.x,touch.y))
                    sam[i].track=k;
                    //printf("%i\n",sam[i].track);
                    sel[i].selecting = false;
            }
        }else{
            //select
            if(zone.rects[i][0].inside(touch.x,touch.y)){
                sel[i].selecting = true;
                sel[i].selected=sam[i].track;
            }
            //record
            if(zone.rects[i][2].inside(touch.x,touch.y)){
                if(sam[i].recording){
                    sam[i].recording=false;
                }else{
                    pat[i].setup(zone.col[i].x,zone.col[i].width);
                    sam[i].recording = true;
                }
            }
            
        }

        
    }

}
//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){}
//--------------------------------------------------------------
void ofApp::exit(){}
//--------------------------------------------------------------
void ofApp::lostFocus(){}
//--------------------------------------------------------------
void ofApp::gotFocus(){}
//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){}
//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){}
