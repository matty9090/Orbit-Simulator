#include "stdafx.h"
#include "Tools.h"

namespace Tools {
	int random(int min, int max) {
		return (rand() % (max - min)) + min;
	}
}