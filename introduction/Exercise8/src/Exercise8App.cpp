#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"
#include "cinder/Perlin.h"
#include "cinder/params/Params.h"
#include "cinder/gl/Fbo.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Exercise8App : public AppBasic {
  public:
	void setup();
	void update();
	void draw();
    
    Perlin perlin_;
    Channel clouds_;
    gl::Texture cloudsTex_;
};

void Exercise8App::setup()
{
    gl::clear( Color( 0, 0, 0 ) );
    clouds_ = Channel(getWindowWidth(), getWindowHeight());
    cloudsTex_ = gl::Texture(getWindowWidth(), getWindowHeight());
}

void Exercise8App::update()
{
    float xoff = 0.0f;
    Channel::Iter iter = clouds_.getIter();
    while (iter.line()) {
        float yoff = 0.0f;
        while (iter.pixel()) {
            float noiseOutput = perlin_.noise(xoff, yoff);
            float brightness = lmap(noiseOutput, -1.0f, 1.0f, 0.0f, 255.0f);
            iter.v() = brightness;
            
            yoff += 0.03;
        }
        xoff += 0.07;
    }
    cloudsTex_.update(clouds_, getWindowBounds());
}

void Exercise8App::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
    gl::draw(cloudsTex_, Vec2f(0.0f, 0.0f));
}

CINDER_APP_BASIC( Exercise8App, RendererGl )
