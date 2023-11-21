#pragma once

#include "CBauelement.h"

class ImpedanzAlgorithmus {
private:

	CBauelement* ptr;
public:

	CKomplex Parallel();
	CKomplex Serien();


};