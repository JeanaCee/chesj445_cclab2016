#include "ofApp.h"

//--------------------------------------------------------------

//--------------------------------------------------------------tutorial first step -----

//calling on the Params param that I added to the header file.

Params param;

void Params::setup() {
    eCenter = ofPoint (ofGetWidth()/2, ofGetHeight ()/2);
    eRad =1000; // how large the radius will be
    velRad = 0; //the speed of the radius
    lifeTime = 5.0; //how long the Params will be alive
    
    rotate = 50; // the degree of rotation
    
    
    force = -200;
    spinning = 300;
    friction = 0.05;
}

//--------------------------------------------------------------tutorial second step, defining the particle functions -----

//this is saying that all of the created particles will be inactive once the program begins. In order to make them come alive, we're going to need do more and call them in the setup function.

Particle :: Particle () {
    live = false;
}


//--------------------------------------------------------------tutorial third step, adding more informationt to the particle system so that it can return properly -----

//before calling the particles in the setup, we have to add more code to tell the particles systems what to return.

ofPoint randomPointInCircle (float maxRad) {
    
    ofPoint pnt; //giving ofPoint a name
    float rad = ofRandom (0, maxRad); //the float radius is going to be openFrameworks Random, at a location of x=0 and the maximum Radius for y.
    
    float angle = ofRandom (0,M_TWO_PI); //not sure if I get this entirely, but I think the angel is also going to be Random, with an X position of zero, and the Y position to incorporate two PI (3.14)
    
    pnt.x = cos (angle) * rad; //then the point X will equal the angle of the cosine, multiplied by the radius dimensions above.
    
    pnt.y = sin (angle) * rad; //then the point Y will equal sine of the angle multiplied by the radius dimensions created above.
    
    return pnt; //and then finally return all of this information into a ofPoint aka pnt.
    
}



//--------------------------------------------------------------tutorial fourth step, now we setup the particle system, but usually wouldn't this be done within it's own class? Going to go ahead and go forward with this tutorial to see where it goes. I'm going to continue to try and break this down how I think it makes sense to me  -----

void Particle :: setup() {
    pos = param.eCenter + randomPointInCircle (param.eRad); //I'm initalizing the setup of the particle by first calling it's position. We created the param in the header as a global variable so I should be able to call on it. I also created the eCenter in the header so now I'm combining the Param and the eCenter to create the X position and adding the RandomPointinCirlce which includes the radius of the Param. I'm still confused on the exact numbers that are being called but going to continue to go forward.
    
    
    
    vel = randomPointInCircle (param.velRad); // here I'm calling on the speed of the Param
    
    
    time = 0; // this will have a short life time of zero
    lifeTime = param.lifeTime;
    live = true; //once the particle system is initalizied it will change from false to true and therefore make it alive.
    
    //Part 3 additions, adding the variables that were just added to the header for force, spinning, and friction
    
  
    
}


//--------------------------------------------------------------tutorial fifth step, now I'm going to write code so the Particle system will have parameters to update. This info will check if the particle system is alive and how fast it will be rotating and also the lifetime of the particle -----

void Particle::update ( float dt) {
    
    
    //---------//This was all Part 1 =------------
    if(live) {
        //if the particle system is alive then rotate it at this speed
        vel.rotate (0,0,param.rotate * dt); //also calling on three parameters so this would possibly create it to be 3D?
        
    //--Part 3 Additions---//
        
        //need to add the accelerations
        ofPoint acc;
        ofPoint delta = pos - param.eCenter;
        float len = delta.length();
        if (ofInRange (len, 0, param.eRad)) {
            delta.normalize ();
            
            
            //add the attraction and repulsion
            
            acc += delta * param.force;
            
            //adding the spinning forces
            acc.x += -delta.y * param.spinning; // I believe this is adding the acceleration of x point and making it equal or more than the spinning of the param object.
            
            acc.y += delta.x * param.spinning;
            
        }
        
        vel += acc * dt; //This is applying the Euler method again
        
        vel *= (1 - param.friction) ; //Friction
    
        
        
        
        //then update the position of the particle system
        
        pos += vel*dt; //this is referencing the Euler Method which I looked up and what I found was that it's used to help simplify more complex usage of math, especially "numerical integration"
        
        //continue to check the position and the particle lifespan
        
        time += dt;
        if ( time >= lifeTime) {
            live = false; // this is once the partilce has died
        }
        
        
    }
}

//-----------------------------------------



//--------------------------------------------------------------tutorial sixth step, drawing the particle system -----

void Particle::draw () {
    if (live) {
        //if the particle system is alive, this is what it will be drawn as
        
        //here I'm writing the size of the particle system
        
        float size = ofMap (
                            fabs (time - lifeTime/2), 0, lifeTime/2, 3, 1);
        
        //next I want to draw the color
        
        ofColor color = ofColor::red;
        float hue = ofMap (time, 0, lifeTime, 255,255);
        color.setHue (hue);
        ofSetColor (255,165,0);
        
        ofCircle (pos, size) ; //this says it will draw the particle, but I want to experiment with creating the circle into a line so it looks more like the map that inspired me.I want to take the same approach with color above as well.
        
    }
}




void ofApp::setup(){
    ofBackground(0);
//    soundPlayer.loadSound("Re.mp3");
//    soundPlayer.play();
    
    ofSetFrameRate (60); //the frame rate determines how fast the screen will update
    
    //here I'm goin to write code that will direct how the drawing will initialize
    
    int w = ofGetWidth(); //integer of width is getting width of openFrameworks
    int h = ofGetHeight (); //integer of height is getting height of openFrameworks
    
    fbo.allocate (w, h, GL_RGB32F_ARB); // this is caling the off screen buffer for trails, but is the third parameter calling the color values with the RGB reference?
    
    //this info below is adding white color to the buffer, which I will experiment with later to change to black to match the color dimensions of my map.
    
    fbo.begin();
    ofBackground (0);
    fbo.end();
    
    
    //then i'm going to set up the parameters fo which it will be built
    param.setup(); //this will be recognized globally based on the tutorial information. Maybe I can manipulate this section to fit towards different parameters of a map or get creative.
    
    
    history = 0.9; //i believe this is referencing the trail history since the value of 1 would be infiinte and the informaiton I read earlier said that 0.8 would be a long trail
    
    bornRate = 10;
    bornCount = 30;
    time0 = ofGetElapsedTimef();
    
    //GOING TO TEST RUN ALL OF THIS 3:56PM to see what's wrong or if it works so I can understand how it's working ... It gave me an error that another porject was running. However, I can still run things when that happens, it also suggested I update some settings so I went forward with that. I think it's cause I haven't drawn anything below that nothing displayed so I'll continue. - JC
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    float dt = ofClamp (time - time0, 0, 0.1);
    time0 = time;
    
    //Get rid of the inactive particles
    
    int i=0;
    while (i <p.size()) {
        if (!p[i].live) {
            p.erase (p.begin() + i );
        }
        else {
            i++;
        }
    }
    
    //Lost my concentration, so trying to get back to how I was understanding this section. Now I'm going to write code so new particles can be born.
    
    bornCount += dt * bornRate;
    if (bornCount>= 1) {
        int bornN = int (bornCount);
        bornCount -= bornN;
        for (int i=0; i<bornN; i++) {
            Particle newP;
            newP.setup();
            p.push_back (newP);
        }
    }
    
    //then update the particles
    for (int i=0; i<p.size (); i++) {
        p[i].update (dt);
    }
    
}



//----pt 1 below---



//next I have to add code so the function will continuously update properly. We need to compute dt (still don't know how this is working properly, distance and time?) and how it activates a particle if the particle is initallly dead

//    float time = ofGetElapsedTimef ();
//    float dt = ofClamp (time - time0, 0,0.1);
//    time0 = time;

//
//    //so by looking at the code above I know that we're as in openFrameworks and I are going to look at the variable of time. Continue working with dt and calculate the current time and time of zero.
//
//    //trying not to get lost, but continuing forward. Sincce the particle is initially dead or false, then we need to tell the system how to update it when it becomes alive. Like telling Frankenstein how to dance once the electricity hits?
//
//    if ( !p.live) {
//        p.setup();
//    }
//
//    //we named particle as p in the header file so we wrote shorter code here for saying once it's alive, then set the dang thing up.
//
//    p.update (dt) ; //then once it's set up, update the particle and dt (hopefully distance and time) accordingly to all the info above that I just wrote. Why do I keep wanting to listen to Chance the Rapper right now? K, focus.
//
//    //holy shit... just confired that dt is a time step that computes the value of the current time and the previous time that the particle system was called to update.

//}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0, 0);
    
    
    fbo.begin();
    
    ofEnableAlphaBlending();
    
    float alpha = (1-history) * 255;
    //wow - just experimented with this and was able to eleiminate the background from being white*******
    //ofSetColor (255,255,255,alpha);
//    ofFill();
    //ofRect (0,0,ofGetWidth(),ofGetHeight());
    
    ofDisableAlphaBlending();
    
    ofFill();
    for (int i=0; i<p.size(); i++ ) {
        p[i].draw();
    }
    
    fbo.end();
    
    ofSetColor (255,255,255);
    fbo.draw (0,0);
    
}

//----All this below was from part 1 or had problems with it with part 2 so going to rewrite the code above ----------------

//    // next we're going to draw this thing, hopefully
//
//    ofBackground (255,255,255); //this example gives a white background, I'm going to later change this color to black or another hue
//
//    //next I need to draw the buffer which was called the fbo
//    fbo.begin(); //initalize to draw the buffer
//
//    //next the tutorial is guiding me to draw a semi transparent rectangle to clear the buffer. I know the similar idea is used for frame rate where it clears the screen each time.
//
//    //took break to go to the restroom and was distracted by a friend wanting food from the student food pantry
//
//    //add the blending
//
//    ofEnableAlphaBlending ();
//
//    float Alpha = (1-history) * 255;
//    ofSetColor ( 255,255,255, Alpha);
//    ofFill ();
//    ofRect (0,0, ofGetWidth(), ofGetHeight ());
//
//    ofDisableAlphaBlending (); //end the transparency
//
//    //now I'll draw the particle
//    ofFill ();
//    p.draw();
//
//
//
//    ofFill();
//    for(int i=0; i<p.size(); i++) {
//        p[i].draw)_;
//    }
//
//
//    fbo.end();
//
//    //now draw the buffer on the screen
//    ofSetColor (255,255,255);
//    fbo.draw (0,0);
//
//    //Going to test run again since now there should be something appearing on the screen.
//
//    //IT Worked!
//    // everthing before here will run single trails of particle systems. The trails curve because of the rotating parameter. If I play with the parameters then hopefully I can create the same effect as the map.

//}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
