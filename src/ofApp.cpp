#include "ofApp.h"
#include "GLFW/glfw3.h"

//--------------------------------------------------------------
void ofApp::setup(){
    auto glfw = ((ofAppGLFWWindow*)ofGetWindowPtr())->getGLFWWindow();
    glfwSetInputMode(glfw,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofLogNotice() << ofGetMouseX() << ", " << ofGetMouseY();
}

//--------------------------------------------------------------
void ofApp::draw(){
    auto x = calcTorus(ofGetMouseX(), ofGetWidth());
    auto y = calcTorus(ofGetMouseY(), ofGetHeight());
    
    ofDrawCircle(x, y, 50);
}

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

int ofApp::calcTorus(int n, int m) {
    if (n >= 0) {
        return n % m;
    } else {
        return m - (-n % m);
    }
}
