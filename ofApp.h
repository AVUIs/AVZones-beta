#pragma once

#include "ofMain.h"
#include "ofxiOS.h"
#include "ofxiOSExtras.h"

#include "ofxMaxim.h"

#include "Cursor.h"
#include "Playlist.h"
#include "Sampler.h"
#include "Selector.h"
#include "Visualizer.h"
#include "Zones.h"
#include "Pattern.h"


class ofApp : public ofxiOSApp{
	
    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);

    void audioOut(float * output, int bufferSize, int nChannels);
    void audioIn(float * input, int bufferSize, int nChannels);
    
    int bufferSize;
    vector <ofPoint> touches;
    
    Cursor filCursor[3], delCursor[3], samCursor[3];
    Sampler sam[3];
    Selector sel[3];
    Visualizer viz[3];
    Zones zone;
    Pattern pat[3];
};


