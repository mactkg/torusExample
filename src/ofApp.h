#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        int calcTorus(int n, int m);
};

class ofApp2 : public ofBaseApp{
    
    public:
        void setup();
        void update();
        void draw();
    
        int calcTorus(int n, int m);

    ofPoint p, pp;
};

class ofApp3 : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    int calcTorus(int n, int m);
    
    ofPoint p, pp;
};

void debugDraw();
