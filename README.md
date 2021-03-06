GrayPlay
========
This project is an attempt in [openframeworks](http://www.openframeworks.cc/) to create a simple projection mapping implementation using kinect and a projector, to be used for a theater [play](https://www.facebook.com/ziuaincarenusecumparanimic).

Development
-----------
I'm learning by doing both programming and GitHub. I started this project by using genekogan's [ofxKinectProjectorToolkit](https://github.com/genekogan/ofxKinectProjectorToolkit) 's example (calibration and bodyMapping) to which I am adding things - and see where it leads. 

Installation
------------
Clone this to the apps folder of your everyday openframework. <br>
Plug kinect (v1) in, update drivers using (.inf) files fom addons\ofxKinect\libs\libfreenect\platform\windows\inf<br>

Usage
-----
####calibrate
- basically the same calibraton process from [ofxKinectProjectorToolkit](https://github.com/genekogan/ofxKinectProjectorToolkit)
- will produce a xml.

Copy the produced xml file to the playbox bin folder.

####playbox
- loads calibration xml, gui presets
- control panel first screen (keys + gui + visual)
- projection screen second screen

Key | Function
:--- | :---
F1-F4 | Save current parameters to a file (save preset)
1-4 | Load parameters from file (load preset)
p | draw/hide elements in the 1st window (production mode)
o | draw/hide a debug projection mapping in the control panel 
i | draw/hide slected contour interactive in 2dBox world
y | draw/hide fbo tests (gui fboTrial++ to see al tests)
b | "Breaks" the selected contour into 2dBox physics triangles (explode)
r | interface "raining" flag makes 2dbox boxes fall from the sky
c | Clears all 2dbox stuff
left,right | select countour

Dependencies
------------
Addons for openframeworks.
- ofxXmlSettings
- ofxOpenCv
- ofxCv
- ofxKinect
- ofxSecondWindow
- ofxKinectProjectorToolkit
- ofxUI
and 
- ofxBox2d 
- ofxColorGradient

Compatibility
------------
Tested with 0.8.3 (win8, win8.1)

Known issues
------------
- I'm learning so this will be very messy. very very messy.
- Resolution in ofApp.h is hard-coded. Changing values would kill the magic.
#define PROJECTOR_RESOLUTION_X 1360
#define PROJECTOR_RESOLUTION_Y 768
#define SCREEN_RESOLUTION_X 1366
#define SCREEN_RESOLUTION_Y 768
- some strange issue with box2d, drawing circles messes up drawing fbo in secondwindow.end


Version history
---------------
### Version 0.2 (2014-09-16):
Removed play and kinect folders, focus is on playbox (box2d+kinectprojectortoolbox)
Added couple of shortcuts to explore interaction between box2d world and the projector calibrated kinect blobs.


### Version 0.1.1 (2014-09-10):
Some copy/paste programming to allow 'presets' to show as proof of concept (currently just color change). 
 - Formatted README
 - Added a 4th screen in the control pannel of play, showing the life performance in control pannel and the real-life kinect
 - Added presets (f1-f4,1-4)
 - Cloned play to playbox and added

### Version 0.1 (2014-09-01):
First version, mostly clones and succesful compliles using visual studio.
 - Cloned calibration and made it work (adding testing=false)
 - Cloned body mapping example 
 - Cloned kinect default example from ofxKinect to be used as a default hw check if kinect works.
