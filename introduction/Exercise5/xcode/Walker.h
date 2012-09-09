/*
 *  Walker.h
 *  RandomWalk
 *
 *  Created by Nathan Koch on 8/27/12
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#include "cinder/Rand.h"

typedef std::shared_ptr<class Walker> WalkerRef;
class Walker {
	
public:
    Walker(float x, float y);
    Walker();

    
    void update();
    void draw();
    
private:
    float x;
    float y;
    int radius;

    ci::Rand generatorStep;
};
