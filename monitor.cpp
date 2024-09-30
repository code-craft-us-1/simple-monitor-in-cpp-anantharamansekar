#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::seconds;

void PrintError(std::string errString)
{
    cout << errString << std::endl;
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
	if (temperature > 102 || temperature < 95) {
		PrintError("Temperature is critical!");
		return 0;
	}
	else if (pulseRate < 60 || pulseRate > 100) {
		PrintError("Pulse Rate is out of range!");
		return 0;
	}
	else if (spo2 < 90) {
		PrintError("Oxygen Saturation out of range!");
		return 0;
	}
  return 1;
}
