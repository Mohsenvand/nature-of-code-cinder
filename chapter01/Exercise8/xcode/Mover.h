/*
 *  Mover.h
 *  Example7
 *
 *  Created by Nathan Koch on 1/2/13
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once


class Mover {
	
  public:
	
	Mover();
	
	void update();
	void draw();
    void checkEdges();
    void setTarget(ci::Vec2f target);
    
    ci::Vec2f mLoc;
    ci::Vec2f mVel;
    ci::Vec2f mTarget;
    float mTopSpeed;
	
};
