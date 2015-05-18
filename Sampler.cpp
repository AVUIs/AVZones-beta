#include "Sampler.h"

void Sampler::setup(int bufferSize, int index){
    myBufferSize=bufferSize;
    list.setup();
    for(int i=0; i<9; i++){
        sound[i].load(ofToDataPath(list.url[index]+list.files[index][i]));
    }
    buffer = new float[bufferSize];
    track=0;
    //properties
    speed=1;
    amplitude=0.5;
    touched=false;
    looping=false;
    //delay
    size = 20000;
    feedback = 0.75;
    //filter
    frequencyLoRes=5000;
    frequencyLoPass=0.5;
    resonance=50;
    filterMix=0.5;
    filterOn=false;
    //
    zone.setup();
}

void Sampler::trigger(float x, float y, int col){
    sampleTrigger=1;
    speed=ofMap(x,zone.rects[col][1].x,zone.rects[col][1].x+zone.rects[col][1].width,-2,2);
    amplitude=ofMap(y,zone.rects[col][1].y,zone.rects[col][1].y+zone.rects[col][1].height,1,0);
}

void Sampler::filter(float x, float y){
    frequencyLoRes=ofMap(x,0,1,200,20000);
    frequencyLoPass=x;
    filterMix = y;
}

void Sampler::delay(float x, float y){
    feedback = ofMap(x,0,1,0.5,0.999);
    size = ofMap(y,0,1,10000,40000);
}

void Sampler::play(int pos, double pan){
    if(looping){
        sampleOut=envelope.ar(sound[track].play(speed), 0.1, 1, 1, sampleTrigger);
    }else{
        sampleOut=envelope.ar(sound[track].play(speed), 0.1, 0.9999, 1, sampleTrigger);
    }
    if(filterOn&&!delayOn){
        filtered=myFilterLoPass.lopass(sampleOut, frequencyLoPass)*filterMix+myFilterLoPass.lores(sampleOut, frequencyLoRes, resonance)*(1-filterMix);
        buffer[pos]=filtered;
        bus.stereo(filtered*amplitude, outputs, pan);
    }else if(delayOn&&!filterOn){
        delayed=myDelayLine.dl(sampleOut,size,feedback);
        buffer[pos]=delayed;
        bus.stereo(delayed*amplitude, outputs, pan);
    }else if(delayOn&&filterOn){
        delayed=myDelayLine.dl(sampleOut,size,feedback);
        filtered=myFilterLoPass.lopass(delayed, frequencyLoPass)*filterMix+myFilterLoPass.lores(delayed, frequencyLoRes, resonance)*(1-filterMix);
        buffer[pos]=filtered;
        bus.stereo(filtered*amplitude, outputs, pan);
        
    }else{
        buffer[pos]=sampleOut;
        bus.stereo(sampleOut*amplitude, outputs, pan);
    }
    sampleTrigger = 0;
}

