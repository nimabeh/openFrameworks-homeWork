#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    ofEasyCam cam;
    ofVideoGrabber vid;
    ofMesh mesh;
    int w = 1280, h = 720;
    int n = w * h;
    void setup() {
        vid.initGrabber(w, h);
        mesh.setMode(OF_PRIMITIVE_POINTS);
        mesh.addVertices(vector<ofVec3f>(n));
        mesh.addColors(vector<ofFloatColor>(n));
        
    }
    void update() {
        vid.update();
        if(vid.isFrameNew()) {
            unsigned char* pix = vid.getPixels();
            int j = 0;
            for(int i = 0; i < n; i++) {
                unsigned char& r = pix[j++];
                unsigned char& g = pix[j++];
                unsigned char& b = pix[j++];
                mesh.setVertex(i, ofVec3f(r+20, g+20, b+20));
                mesh.setColor(i, ofColor(r+20, g+20, b+20));
            }
        }
    }
    void draw() {
        ofBackground(100);
        cam.begin();
        ofSetColor(ofRandom(255), ofRandom(255),ofRandom(255));
        ofDrawBox(0, 0, 0, 200, 200, 200);
        ofTranslate(-128, -128, -128);
        mesh.draw();
        cam.end();

    }
};

int main() {
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofRunApp(new ofApp());
}
