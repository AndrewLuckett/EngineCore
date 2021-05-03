#include "Shorts.h"

namespace Engine {
	struct version {
		uchar major;
		uchar minor;
		uchar revision;
	};

	extern version CurrentVersion;

	string versionToString(version v);
}

