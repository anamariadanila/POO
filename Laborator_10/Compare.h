#pragma once
class Compare
{

public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class CompareInt : public Compare {
public:
	virtual int CompareElements(void* e1, void* e2) {
		int val1 = *((int*)e1);
		int val2 = *((int*)e2);
		return val1 < val2;
	}
};