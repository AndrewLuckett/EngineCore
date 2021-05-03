#include "System.h"

int System::update(timesys::system_clock::duration deltaTime) { //Perform every frame
	for (auto const& i : subsystems) {
		i->update(deltaTime);
	}
	return 0;
}

int System::fixedUpdate() { //Perform every fixed amount of time
	for (auto const& i : subsystems) {
		i->fixedUpdate();
	}
	return 0;
}

int System::getRenderArr(std::queue<Model> &arr){
	for (auto const& i : subsystems) {
		i->getRenderArr(arr);
	}
	return 0;
}

int System::cleanup() {
	for (auto const& i : subsystems) {
		i->cleanup();
	}
	return 0;
}

int System::addSubSystem(System * sys) {
	subsystems.emplace_front(sys);
	return 0;
}
