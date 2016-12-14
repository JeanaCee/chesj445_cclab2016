#pragma once

#include "ofMain.h"

//Adding on to this project to add repulsion and spinning force


class Particle {
public:
    Particle ();
    void setup();
    void update (float dt); //I don't remember using this dt function before, but in this tutorial it's used to help with the timing of space in between each particle being generated.
    
    void draw ();
    
    ofPoint pos;
    ofPoint vel;
    float time;
    float lifeTime;
    bool live;
    
};

//To help with the lifespan of each partilce and it's speed (velocity) I'm following the tutorial's steps here to create another class.

class Params {
public:
    void setup ();
    ofPoint eCenter;
    float eRad;
    float velRad;
    float lifeTime;
    
    float rotate;
    
    //Part 3 additions to add force,spinning, and friction
    float force;
    float spinning;
    float friction;
    
};

extern Params params; // the params is making this accessible in each file or other words global. I'm drawing attention to it here, but in order for it to work I need to add it to the cpp file. This could be considered an object?



class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    
    //Pt.1 for only a single particle - //naming the particle itself
    
    //Particle p;
    
    //Pt.2 adding an array of particles. I'm going to replace the code above with the array below
    
    vector <Particle> p;
    
    
    ofFbo fbo; //used as an offscreen buffer for trails
    
    float history; //this will be helping to control how long the particle will trail on the screen. A value of 0.0 means that the trails dissapear immediately. Yet, the value of 1.0  would mean the trails are infinite. To get long trails try anything from 0.5-0.8.
    
    float time0;// the time value for computing the dt... what the hell is the dt... go back and read.
    
    //Pt.2 Additions - going to add bornRate and bornCount to determine how Particles are born. In order to initialize the bornRate and bornCount we need to add it to the update.
    
    float bornRate;
    float bornCount;
    
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
//    ofSoundPlayer soundPlayer;
    
};
