#include "ofApp.h"
#include "GLFW/glfw3.h"

//--------------------------------------------------------------
// First Proto: experimentation of glfwSetInputMode
//--------------------------------------------------------------
void ofApp::setup(){
    auto glfw = ((ofAppGLFWWindow*)ofGetWindowPtr())->getGLFWWindow();
    glfwSetInputMode(glfw,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
    
}

void ofApp::update(){
    ofLogNotice() << ofGetMouseX() << ", " << ofGetMouseY();
}

void ofApp::draw() {
    auto x = calcTorus(ofGetMouseX(), ofGetWidth());
    auto y = calcTorus(ofGetMouseY(), ofGetHeight());
    
    ofDrawCircle(x, y, 50);
}

int ofApp::calcTorus(int n, int m) {
    if (n >= 0) {
        return n % m;
    } else {
        return m - (-n % m);
    }
}

//--------------------------------------------------------------
// Second Proto: implement torus cursor system using
//               ofGetMouseX/ofGetPreviousMouseX
//--------------------------------------------------------------
void ofApp2::setup(){
    auto glfw = ((ofAppGLFWWindow*)ofGetWindowPtr())->getGLFWWindow();
    glfwSetInputMode(glfw,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
    
    p = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    pp = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
}

void ofApp2::update(){
    p.x = calcTorus(p.x + ofGetMouseX() - ofGetPreviousMouseX(), ofGetWidth());
    p.y = calcTorus(p.y + ofGetMouseY() - ofGetPreviousMouseY(), ofGetHeight());
}

void ofApp2::draw() {
    ofDrawCircle(p, 50);
    debugDraw();
}

int ofApp2::calcTorus(int n, int m) {
    if (n >= 0) {
        return n % m;
    } else {
        return m - (-n % m);
    }
}

//--------------------------------------------------------------
// Third Proto: implement torus cursor system using
//               hand-made ofGetPreviousMouseX
//--------------------------------------------------------------
void ofApp3::setup(){
    auto glfw = ((ofAppGLFWWindow*)ofGetWindowPtr())->getGLFWWindow();
    glfwSetInputMode(glfw,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
    
    p = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    pp = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
}

void ofApp3::update(){
    p.x = calcTorus(p.x + ofGetMouseX() - pp.x, ofGetWidth());
    p.y = calcTorus(p.y + ofGetMouseY() - pp.y, ofGetHeight());
    pp.set(ofGetMouseX(), ofGetMouseY());
}

void ofApp3::draw() {
    ofDrawCircle(p, 50);
}

int ofApp3::calcTorus(int n, int m) {
    if (n >= 0) {
        return n % m;
    } else {
        return m - (-n % m);
    }
}

void debugDraw() {
    ofPushStyle();
    
    ofSetColor(255, 0, 0);
    ofDrawLine(ofGetMouseX(), 0, ofGetMouseX(), ofGetHeight());
    ofDrawLine(0, ofGetMouseY(), ofGetWidth(), ofGetMouseY());
    
    ofSetColor(0, 255, 0);
    ofDrawLine(ofGetPreviousMouseX(), 0, ofGetPreviousMouseX(), ofGetWidth());
    ofDrawLine(0, ofGetPreviousMouseY(), ofGetWidth(), ofGetPreviousMouseY());
    
    ofSetColor(0, 0, 255);
    ofDrawLine(ofGetMouseX(), ofGetMouseY(), ofGetPreviousMouseX(), ofGetPreviousMouseY());
    
    ofPopStyle();
}
