#include "Model.h"
#include "../global/Shorts.h"

namespace renderer {
	int init();
	int clearScreen();
	int draw(Model &model);
	int loadGlobalTransform(uint progID, TransMatrix mat);
	int pushToScreen();
	int setProgram(uint progId);
}