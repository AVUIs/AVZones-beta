#include "ofMain.h"
#include "ofApp.h"

int main(){
    
    //retina code starts
    
    ofAppiOSWindow *window = new ofAppiOSWindow();
    window->enableRetina();
    window->enableAntiAliasing(2);

    //retina code ends
    
	ofSetupOpenGL(1024,768, OF_FULLSCREEN);			// <-------- setup the GL context

	ofRunApp(new ofApp);
}
