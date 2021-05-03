#pragma once
#include "System.h"
#include <array>
#include "../render/Model.h"

class FrameCounter : public System {
    public:
		FrameCounter();
		int update(timesys::system_clock::duration deltaTime);
		int fixedUpdate();
		int getRenderArr(std::queue<Model> &arr);
		int cleanup();
    private:
	    Model getCell();

		timesys::system_clock::duration sumTime;
		uint frames;
		int fps;
		Model out;
		std::array<uint,10> textures;
};