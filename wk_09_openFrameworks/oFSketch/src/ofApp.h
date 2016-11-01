#pragma once

#include "ofMain.h"
//#include "particles.hpp"
#include "PlanetClass.hpp"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    //vector<Particle> particles;
    int num;
    
    ofParameterGroup planetGroups;
    PlanetClass planet01;
    
    
    //vector
    
    //this holds all of our points
    vector<ofVec3f> points;
    //this keeps track of the center of all the points
    ofVec3f center;
    
    
    
    ofCamera camera;
    
    //if usecamera is true, we'll turn on the camera view
    bool usecamera;
    //
};
