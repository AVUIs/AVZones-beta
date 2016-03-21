#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

#include "Playlist.h"
#include "Zones.h"

class Sampler {
    
    public:
        void setup(int bufferSize, int index);
        void trigger(float x, float y, int col);
        void filter(float x, float y);
        void delay(float x, float y);
        void play(int pos, double pan);

        //objects
        maxiEnv envelope;
        maxiSample sound[9];
        maxiMix bus;
        maxiFilter myFilterLoRes, myFilterLoPass;
        maxiDelayline myDelayLine;
        Playlist list;
        Zones zone;
    
        //audio streams
        double outputs[2];
        double sampleOut;
        double filtered;
        double delayed;
        float * buffer;

        //properties
        double speed;
        double amplitude;
        bool touched;
        bool looping;
        bool recording;
        int myBufferSize;
        int sampleTrigger;
        int index;
        int track;

        //filter
        double frequencyLoRes;
        double frequencyLoPass;
        double resonance;
        double filterMix;
        bool filterOn;
    
        //delay
        double size;
        double feedback;
        bool delayOn;

};