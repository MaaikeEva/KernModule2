#include "ofApp.h"


void ofApp::setup(){
	grabber.setup(640, 480);
	haarFinder.setup("haarcascade_eyes.xml");

	image.load("eyes.png");
}

void ofApp::update(){
	grabber.update();

	if (grabber.isFrameNew()) {
		haarFinder.findHaarObjects(grabber.getPixels(), 100, 100);
	}
}

void ofApp::draw(){
	grabber.draw(0, 0);

	ofSetColor(ofColor::red);
	for (int i = 0; i < haarFinder.blobs.size(); ++i) {
		if (drawBox) {
			ofRectangle boundingBox = haarFinder.blobs[i].boundingRect;
				ofDrawRectangle(boundingBox);
		}
		if (drawImage) {
			ofRectangle boundingBox = haarFinder.blobs[i].boundingRect;
			image.draw(boundingBox);
		}
	}
}


void ofApp::keyPressed(int key){
	if (key == 'b') {
		drawBox = !drawBox;
	}
	else if (key == 'i') {
		drawImage = !drawImage;
	}
}

