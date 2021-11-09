#ifndef WAVE_H
#define WAVE_H
#include "WaveType.h"
class Wave {
public:
	Wave();
	virtual double ReturnWave(double dTime);
	void setAmplitude(int Amplitude);

	WaveType getWaveType();
	void setWaveType(WaveType type);
	double Gain;

private:
	WaveType wave_type; 
	double amplitude;
	
};

#endif