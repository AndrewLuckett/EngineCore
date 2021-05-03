#pragma once
#include <chrono>
#include "System.h"

class GameMain : public System {
    public:
		GameMain();
	    int update(timesys::system_clock::duration deltaTime);
    private:
	    timesys::system_clock::time_point fuLastRun;
	    timesys::system_clock::time_point suLastRun;
	    timesys::system_clock::duration fuTime = timesys::milliseconds(100);
	    timesys::system_clock::duration deltaTime;
};