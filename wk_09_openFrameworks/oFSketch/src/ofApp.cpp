#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    //vector
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    //particles
    num = 800;
    for(int i =0; i< num; i++){
        
        //used if I kept the particles -- initialize the array
        //Particle tempVar;
        //tempVar.setup();
        //particles.push_back(tempVar);
        
        
        
    }
    
    //planets
    planet01.setup();
    
    planetGroups.add(planet01.planetGroup);
    
    //    gui.setup(planetGroups);
    
    // vector camera
    usecamera = false;
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    //planet
    
    planet01.update();
    
    //vector camera
    
    if(!usecamera){
        ofVec3f sumOfAllPoints(0,0,0);
        for(unsigned int i = 0; i < points.size(); i++){
            points[i].z -= 4;
            sumOfAllPoints += points[i];
        }
        center = sumOfAllPoints / points.size();
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //planet
    
    //    ofSetColor(255,96,58);
    //    //    ofRotate(roatation * roatateSpeed);
    //    //    ofCircle(posX, posY, 30);
    //    ofSphere(900, 200, 100);
    
    
    
    //    gui.draw();
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    planet01.draw ();
    
    
    //camera
    
    if(usecamera){
        camera.begin();
    }
    
    ofSetColor(0, 255, 255);
    ofDrawSphere(200, 200, 200, 100);
    
    //    ofSetColor(0, 255, 255);
    //    ofDrawSphere(200, 200, 100, 100);
    //
    //    ofSetColor(0, 255, 255);
    //    ofDrawSphere(200, 200, 50, 50);
    
    
    ofSetColor(255,255,0);
    ofDrawRectangle(100, 100, 100, 100);
    
    
    //if we're using the camera, take it away
    if(usecamera){
        camera.end();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    
    //vector camera
    usecamera = !usecamera;
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
    if(usecamera){
        float rotateAmount = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 360);
        ofVec3f furthestPoint;
        if (points.size() > 0) {
            furthestPoint = points[0];
        }
        else
        {
            furthestPoint = ofVec3f(x, y, 0);
        }
        
        ofVec3f directionToFurthestPoint = (furthestPoint - center);
        ofVec3f directionToFurthestPointRotated = directionToFurthestPoint.getRotated(rotateAmount, ofVec3f(0,1,0));
        camera.setPosition(center + directionToFurthestPointRotated);
        camera.lookAt(center);
    }
    //otherwise add points like before
    else{
        ofVec3f mousePoint(x,y,0);
        points.push_back(mousePoint);
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}