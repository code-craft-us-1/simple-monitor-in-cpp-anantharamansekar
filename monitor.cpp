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

bool CheckTemperature(float temperature) {
    bool result = true;

    if (temperature > 102 || temperature < 95) {
        PrintError("Temperature is critical!");
        result = false;
    }

    return result;
}

bool CheckPulse(float pulseRate) {
    bool result = true;

    if (pulseRate < 60 || pulseRate > 100) {
        PrintError("Pulse Rate is out of range!");
        result = false;
    }

    return result;
}

bool CheckSPO2(float spo2) {
    bool result = true;

    if (spo2 < 90) {
        PrintError("Oxygen Saturation out of range!");
        result = false;
    }

    return result;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    bool result = true;

    result = CheckTemperature(temperature);

    if (result) {
        result = CheckPulse(pulseRate);
    }

    if (result) {
        result = CheckSPO2(spo2);
    }

    return result;
}
