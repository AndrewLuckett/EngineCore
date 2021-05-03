#pragma once
#include "../render/Model.h"
#include <list>
#include <chrono>
#include <queue>

namespace timesys = std::chrono;

class System {
    public:
	    virtual int update(timesys::system_clock::duration deltaTime);
		virtual int fixedUpdate();

		virtual int getRenderArr(std::queue<Model> &arr); //Gets SSDat for elements and returns them
			
		int cleanup();

		int addSubSystem(System* sys);
    protected:
	    std::list<System*> subsystems;
};