#include "Version.h"

namespace Engine {
	extern version CurrentVersion = { 0,1,2 };

	string versionToString(version v) {
		return std::to_string(v.major) + "." + std::to_string(v.minor) + "." + std::to_string(v.revision);
	}
}