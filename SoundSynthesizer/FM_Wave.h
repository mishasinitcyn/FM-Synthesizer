#pragma once
#include "Wave.h"
#include <vector>
using namespace std;

class FM_Wave : public Wave {
public:
	FM_Wave();
	void addWave(Wave inputWave);
	Wave getWave();
	virtual double ReturnWave(double dTime);
	~FM_Wave();
private:
	vector<Wave> Waves;
};