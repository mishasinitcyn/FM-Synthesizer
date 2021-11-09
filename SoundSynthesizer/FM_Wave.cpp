//Misha Sinitcyn 2021
//Custom class that combines wave functions into a single function
#include "FM_Wave.h"

FM_Wave::FM_Wave() : Wave(){

}

//Saves wave functions in a vector
void FM_Wave::addWave(Wave inputWave) {
	this->Waves.push_back(inputWave);
}


//Iterates through waves vector combining them into one
double FM_Wave::ReturnWave(double dTime) {
	double output = 0;
	std::vector<Wave>::iterator it = Waves.begin();
	
	for (Wave it : Waves) {
		output += it.ReturnWave(dTime);
	}
	
	return output;
}

FM_Wave::~FM_Wave() {

}
