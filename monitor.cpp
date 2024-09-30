#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::seconds;

void PrintError(std::string errString) {
    cout << errString << std::endl;
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

int CheckTemperature(float temperature) {
    int result = 1;

    if (temperature > 102 || temperature < 95) {
        PrintError("Temperature is critical!");
        result = 0;
    }

    return result;
}

int CheckPulse(float pulseRate) {
    int result = 1;

    if (pulseRate < 60 || pulseRate > 100) {
        PrintError("Pulse Rate is out of range!");
        result = 0;
    }

    return result;
}

int CheckSPO2(float spo2) {
    int result = 1;

    if (spo2 < 90) {
        PrintError("Oxygen Saturation out of range!");
        result = 0;
    }

    return result;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    int result = 1;

    result = CheckTemperature(temperature);

    if (result) {
        result = CheckPulse(pulseRate);
    }

    if (result) {
        result = CheckSPO2(spo2);
    }

    return result;
}
