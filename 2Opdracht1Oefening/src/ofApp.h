#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

#define GRABBER_WIDTH 320
#define GRABBER_HEIGHT 240
#define HUE_MARGIN 5
#define MIN_SIZE 50

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void mousePressed(int x, int y, int button);
		void keyPressed(int key);

		ofVideoGrabber grabber;
		ofxCvColorImage rgbImage;
		ofxCvColorImage hsvImage;

		ofxCvGrayscaleImage hue;
		ofxCvGrayscaleImage saturation;
		ofxCvGrayscaleImage value;

		ofxCvGrayscaleImage filtered;

		ofxCvContourFinder contours;

		int selectedHue;

		bool showHSVComponents = false;
		bool showVideo = true;
		bool showFiltered = true;
		bool showContours;

		int findHue; 
};
