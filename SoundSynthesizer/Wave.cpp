//Misha Sinitcyn, 2021
//Custom Wave class that stores Amplitude, Gain, and Wave Type
#include "Wave.h"
#include <math.h>

Wave::Wave(){
	//Sets default values to regular sine wave
	this->amplitude = 2;
	this->wave_type = WaveType::SIN;
	this->Gain = 1;
}


double Wave::ReturnWave(double dTime) {
	switch (wave_type) {
	case(SIN):
		return 0.5 * sin(440 * amplitude * 3.14 * dTime) * Gain;
		break;
	case(COS):
		return 0.5 * cos(440 * amplitude * 3.14 * dTime) * Gain;
		break;
	case(TRI):
		return asin(sin(440*amplitude*3.14*dTime)) * Gain * (2.0 / 3.14);
		break;
	case(SQUARE): 
		//Doesn't work when combined with other waves
		return Gain * (sin(440*amplitude*3.14*dTime) > 0 ? 1.0 : -1.0);
		break;
	}

}

WaveType Wave::getWaveType() {
	return this->wave_type;
}

void Wave::setAmplitude(int Amplitude) {
	this->amplitude = Amplitude;
}

void Wave::setWaveType(WaveType type) {
	this->wave_type = type;
}

