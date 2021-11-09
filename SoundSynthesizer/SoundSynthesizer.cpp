//Misha Sinitcyn 2021
//Simple FM Synthesizer based on Sound Synthesizer project by javidx9: https://www.youtube.com/watch?v=tgamhuQnOkM
//WaveType.h, FM_Wave.cpp, FM_Wave.h, Wave.cpp, Wave.h, and most of this file were written by me

#include <iostream>
#include "olcNoiseMaker.h"
#include "Wave.h"
#include "FM_Wave.h"

using namespace std;

double Wave1(double dTime) {
	return 0.5 * sin(440 * 2 * PI * dTime);
}

//Created instance of combined wave to add wave types onto
FM_Wave CombinedWave;


//Returns CombinedWave as a function
double MakeNoise(double dTime) {
	return CombinedWave.ReturnWave(dTime);
}




int main(void)
{
	wcout << "Synthesizer" << endl;

	//Get all sound hardware
	vector<wstring> devices = olcNoiseMaker<short>::Enumerate();

	//Display findings
	for (auto d : devices) wcout << "Found Output Device: " << d << endl;
	

	//Initialize values to store user input
	int waveNum;
	Wave tempWave; int tempWaveType; double tempAmplitude; double tempGain;
	cout << "# of Waves: ";
	cin >> waveNum;	cout << endl;
	
	for (int i = 0; i < waveNum; i++) {
		cout << "WaveType (1 SIN, 2 COS, 3 TRI): ";
		cin >> tempWaveType; cout << endl;
		tempWave.setWaveType(WaveType(tempWaveType));

		cout << "Amplitude: ";
		cin >> tempAmplitude; cout << endl;
		tempWave.setAmplitude(tempAmplitude);

		cout << "Gain: ";
		cin >> tempGain; cout << endl;
		tempWave.Gain = tempGain;

		CombinedWave.addWave(tempWave);
	}


	//Create sound machine
	olcNoiseMaker<short> sound(devices[0], 44100, 1, 8, 512);

	//Link noise function with sound machine
	sound.SetUserFunction(MakeNoise);

	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
