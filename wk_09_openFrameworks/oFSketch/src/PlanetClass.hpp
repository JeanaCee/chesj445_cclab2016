//
//  PlanetClass.hpp
//  emptyExample
//
//  Created by Jeana Chesnik on 10/20/16.
//
//

#ifndef PlanetClass_hpp
#define PlanetClass_hpp

#include "ofMain.h"

class PlanetClass {
public:
    void setup ();
    void update ();
    void draw ();
    
    ofParameterGroup planetGroup;
    ofParameter<float> roatateSpeed;
    ofParameter<float> posX;
    ofParameter<float> posY;
    ofParameter<int> red;
    ofParameter<int> green;
    ofParameter<int> blue;
    
    float roatation = 4.0;
    
    
};

#endif /* PlanetClass_hpp */
