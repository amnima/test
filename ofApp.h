#pragma once

#include "ofMain.h"
#include <memory>
#include <vector>
#include "ofxGui.h"
#include "ofMain.h"
#include "base.h"
#include "planet.h"
#include "sun.h"
#include "solarsystem.h"


class ofApp : public ofBaseApp{

private:

        int  m_nPlanets;
        int  m_nSuns;
        int  m_traceSize;
        float m_planetRadiusMax;
        float m_planetRadiusMin;
public:
        std::shared_ptr <SolarSystem>  m_solarSystem;
        std::vector <ofLight>  m_lights;
        std::vector <ofPolyline> m_traces;


        ofEasyCam   m_cam;
        ofSpherePrimitive   m_sphere;
        ofLight   m_globalLight;
        ofMaterial   m_material;
        ofMaterial   m_sunMaterial;
        ofxPanel  m_gui;
        ofxIntSlider  m_planetCountSlider;
        ofxIntSlider m_sunCountSlider;

        ofxFloatSlider trace_length;
        ofxFloatSlider planetRadiusMaxSlider;
        ofxFloatSlider planetRadiusMinSlider;
        ofxFloatSlider planetSpeedMaxSlider;
        ofxFloatSlider planetSpeedMinSlider;
        ofxFloatSlider planetMassMaxSlider;
        ofxFloatSlider planetMassMinSlider;









        void setup();
        void update();
        void draw();
        void initSolarSystem();
        void planetCountChanged(int &value);
        void sunCountChanged(int &value);
        void planetRadiusMaxChanged(float &value);
        void planetRadiusMinChanged(float &value);

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
        float FRAME_RATE = 0;
        float frame_num;
        float x,y,z = 0.0;
};
