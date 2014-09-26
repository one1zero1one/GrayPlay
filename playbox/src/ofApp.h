#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxKinect.h"
#include "ofxSecondWindow.h"
#include "ofxKinectProjectorToolkit.h"
#include "ofxUI.h"
#include "ofURLFileLoader.h"
#include "ofxColorGradient.h"
#include "ofxBox2d.h"

// this must match the display resolution of your projector (however, I did not _test_ another resolution)
#define PROJECTOR_RESOLUTION_X 1360
#define PROJECTOR_RESOLUTION_Y 768

// this is the control panel screen
#define SCREEN_RESOLUTION_X 1366
#define SCREEN_RESOLUTION_Y 768

using namespace ofxCv;
using namespace cv;

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void update_rain();
	void draw();
	void drawCtrl();
	void drawDebug();
	void drawProj();
	void drawContours(int width,int height, bool debugProjector);
	void drawProjSandbox();
	void exit();
	void keyPressed(int key);
	void explodeShape();

	ofxSecondWindow             secondWindow;

	ofxUICanvas                 *gui;
	void guiEvent(ofxUIEventArgs &e);

	ofxCv::ContourFinder        contourFinder;
	ofxKinectProjectorToolkit   kpt;
	ofxKinect                   kinect;

	ofxCvGrayscaleImage         bgImage;
	ofxCvGrayscaleImage         grayImage;
	ofxCvGrayscaleImage         grayThreshNear;
	ofxCvGrayscaleImage         grayThreshFar;

	float                       nearThreshold;
	float                       farThreshold;
	float                       minArea;
	float                       maxArea;
	float                       threshold;
	float                       persistence;
	float                       maxDistance;

	bool						isProductive;
	bool						isContours;
	bool						isCtrlComposite; //Compile composite image with synced projector in the control panel
	bool						isBroken;	// break triangles?
	bool						isRaining; // trhow boxes from the sky
	bool						isInteractive; // interacting with the elements
	bool						isExplosion; //used for DURING the explosion
	bool						isExplosionStart; 
	bool						isExplosionEnd; 
	bool						isGround; //box2d bottom
	
	float						timer1; //used for dropping boxes frequence
	float						timer2; //used for interactive shape refresh 
	float						contourTimer; //the actual milisecond value for timer2
	float						gradientPhase; // gradient loop increments (speed of the change of color)
	
	float						preset; //preset gui var
	int							contourSelected; //the selected contour by means of keys left right :)
	float						contoursOnscreen; //total contours (at the end of update)

	ofxColorGradient			gradient;  //one set of color scheme.
	float						gradienti; //loop through colors
	int							colorDebug, colorContour, colorSelectedContour, colorInteractiveShape, colorBoxes, colorCircles, colorExplodingShape, colorPolishape;

	void urlResponse(ofHttpResponse & response);
	ofImage img;
	bool loading;

	ofxBox2d                            box2d;						//	the box2d world
	ofxBox2dEdge                        movingShape;			//	the box2d edge/line shape (min 2 points)
	ofPolyline							explodingShapeLine;			// for capture and explode
	ofPolyline							movingShapeLine;			// for moving
	//vector	 <ofPtr<ofxBox2dEdge> >		movingShapes;		//to be used when multiple contours are interactive
	vector	  <ofPtr<ofxBox2dPolygon> >	polyShapes;		  //    pieces of shape maybe eh?
	vector    <ofPtr<ofxBox2dCircle> >	circles;		  //	default box2d circles
	vector	  <ofPtr<ofxBox2dRect> >	boxes;			  //	defalut box2d rects

};
