#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

        ofSetFrameRate(60.0);

        ofEnableDepthTest();
        ofEnableAntiAliasing();

        m_gui.setup();
        //SLIDERS ADDITION BEGINS: The sliders are inteded to change objects attributes
        m_gui.add(m_planetCountSlider.setup("Num of planets", m_nPlanets,0,10));
        // to be able to respoind to user interface changes an event method must also be added
        m_planetCountSlider.addListener(this, &ofApp::planetCountChanged);
        // adding trace
        m_gui.add(trace_length.setup("TRACE LENGTH", m_traceSize,0,200));

        //adding sun count slider as integer
        m_gui.add(m_sunCountSlider.setup("Nums of Suns",m_nSuns,0,4));
        m_sunCountSlider.addListener(this, &ofApp::sunCountChanged);
        //float sliders

        m_gui.add(planetRadiusMaxSlider.setup("planet radius max",m_planetRadiusMax,0,100));
        planetRadiusMaxSlider.addListener(this, &ofApp::planetRadiusMaxChanged);

        m_gui.add(planetRadiusMinSlider.setup("planet radius min",m_planetRadiusMin,0,30));
        planetRadiusMinSlider.addListener(this, &ofApp::planetRadiusMinChanged);

        // adding speed sliders
       // g_gui.add(planetSpeedMaxSlider.setup("planet speed max",));

        // END OF SLIDERS ADDITION:
        m_nPlanets = 1000;
        m_nSuns = 4;
        m_traceSize = 200;
        m_sphere.set(1.0, 10);
        m_globalLight.setPosition(0, 0, 0);
        m_globalLight.setDirectional();
        m_material.setDiffuseColor(ofColor(200, 100, 0));
        m_sunMaterial.setDiffuseColor(ofColor(200, 100, 0));
        m_sunMaterial.setEmissiveColor(ofColor(250, 150, 0));
        m_cam.setDistance(100);
        // creating an instance of solar_system
        m_solarSystem = std::make_shared<SolarSystem>(m_nPlanets, m_nSuns);
        this -> initSolarSystem();
}


void ofApp::initSolarSystem(){
        m_solarSystem->setSize(m_nPlanets, m_nSuns);
        m_solarSystem->init();
        m_lights.clear();
        m_lights.resize(m_solarSystem->sunCount());
        m_lights.resize(m_solarSystem->planetCount());

        for (auto i = 0; i < m_solarSystem->sunCount(); i++)
                m_lights[i].setPosition(
                        m_solarSystem->sunAt(i)->location().x(),
                        m_solarSystem->sunAt(i)->location().y(),
                        m_solarSystem->sunAt(i)->location().z()
                            );
        for (auto j = 0; j < m_solarSystem->planetCount(); j++)
                m_lights[j].setPosition(
                        m_solarSystem->planetAt(j)->location().x(),
                        m_solarSystem->planetAt(j)->location().y(),
                        m_solarSystem->planetAt(j)->location().z()
                            );


}


//--------------------------------------------------------------
void ofApp::update(){
    FRAME_RATE = ofGetFrameRate();

    if (FRAME_RATE < 60){
        FRAME_RATE ++;
    }


    this->planetCountChanged(m_nPlanets);
    this->sunCountChanged(m_nSuns);
    this->planetRadiusMaxChanged(m_planetRadiusMax);
    this->initSolarSystem();

}

//--------------------------------------------------------------
void ofApp::draw(){

        ofEnableDepthTest();
        ofClear(ofColor::black);
        ofEnableLighting();
        m_cam.begin();
        m_cam.setScale(1, -1, 1);
        m_cam.setPosition(ofGetWidth()/2,ofGetHeight()/2,1200);
        //####################################################################
        // planet addition begins
        m_material.begin();
        for (auto light : m_lights)
                light.enable();


        // planet1
        m_sphere.setPosition(600, 600, 0);
        m_sphere.setScale(50,50,50);
        m_sphere.draw();


        // following lines draw the traces without lighting
        ofDisableLighting();
        for (auto trace : m_traces)
        {
                ofSetColor(100, 50, 0);
                trace.draw();
        }
        ofEnableLighting();

        m_material.end();
        for (auto light : m_lights)
                light.disable();
        //planet addition ends
        //####################################################################



        // Draw sun
        m_globalLight.enable();
        m_sunMaterial.begin();

        m_sphere.setPosition(200, 200, 0);
        m_sphere.setScale(50,50,50);
        m_sphere.draw();

        m_sunMaterial.end();
        m_globalLight.disable();
        m_cam.end();


        // ---- Draw user interface ----
        ofDisableLighting();
        ofDisableDepthTest();
        m_gui.draw();
}






void ofApp::planetCountChanged(int &value)
{
    m_nPlanets = value;
    this->initSolarSystem();
}

void ofApp::sunCountChanged(int &value)
{
    m_nSuns = value;
    this->initSolarSystem();
}

void ofApp::planetRadiusMaxChanged(float &value)
{
    m_planetRadiusMax = value;
    this->initSolarSystem();
}


void ofApp::planetRadiusMinChanged(float &value)
{
    m_planetRadiusMin = value;
    this->initSolarSystem();
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
