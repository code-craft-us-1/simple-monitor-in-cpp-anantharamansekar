// monitor.cpp
#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>

using namespace std;
using namespace chrono;

// Function: PrintError
// Description: This function prints an error message to the console and creates a blinking effect
// to draw attention to the error.
// Parameters:
//   - const string& errorMessage: A constant reference to a string containing the error message
//     to be displayed.
// Returns: void
// Usage: Call this function with an error message to alert the user with a blinking effect.
void PrintError(const string& errorMessage) {
    cout << errorMessage << endl;
    for (int blinkCount = 0; blinkCount < 6; ++blinkCount) {
        cout << "\r* " << flush;
        this_thread::sleep_for(seconds(1));
        cout << "\r *" << flush;
        this_thread::sleep_for(seconds(1));
    }
}

// Function: CheckTemperature
// Description: This function checks if the provided temperature is within the acceptable range
// (95 to 102 degrees Fahrenheit).
// Parameters:
//   - float temperature: The temperature value to be checked.
// Returns: bool
//   - Returns true if the temperature is within the acceptable range.
//   - Returns false and prints an error message if the temperature is outside the acceptable
//     range.
// Usage: Call this function with a temperature value to verify if it is within the normal range.
bool CheckTemperature(float temperature) {
    if (temperature > 102 || temperature < 95) {
        PrintError("Temperature is critical!");
        return false;
    }
    return true;
}

// Function: CheckPulse
// Description: This function checks if the provided pulse rate is within the acceptable range
// (60 to 100 beats per minute).
// Parameters:
//   - float pulseRate: The pulse rate value to be checked.
// Returns: bool
//   - Returns true if the pulse rate is within the acceptable range.
//   - Returns false and prints an error message if the pulse rate is outside the acceptable
//     range.
// Usage: Call this function with a pulse rate value to verify if it is within the normal range.
bool CheckPulse(float pulseRate) {
    if (pulseRate < 60 || pulseRate > 100) {
        PrintError("Pulse Rate is out of range!");
        return false;
    }
    return true;
}

// Function: CheckSPO2
// Description: This function checks if the provided oxygen saturation level (SPO2) is within the
// acceptable range (90% and above).
// Parameters:
//   - float spo2: The oxygen saturation level to be checked.
// Returns: bool
//   - Returns true if the oxygen saturation level is within the acceptable range.
//   - Returns false and prints an error message if the oxygen saturation level is below the
//     acceptable range.
// Usage: Call this function with an oxygen saturation level value to verify if it is within the
// normal range.
bool CheckSPO2(float spo2) {
    if (spo2 < 90) {
        PrintError("Oxygen Saturation out of range!");
        return false;
    }
    return true;
}

// Function: vitalsOk
// Description: This function checks if all provided vital signs (temperature, pulse rate, and
// oxygen saturation) are within their respective acceptable ranges.
// Parameters:
//   - float temperature: The temperature value to be checked.
//   - float pulseRate: The pulse rate value to be checked.
//   - float spo2: The oxygen saturation level to be checked.
// Returns: int
//   - Returns 1 (true) if all vital signs are within their acceptable ranges.
//   - Returns 0 (false) if any of the vital signs are outside their acceptable ranges.
// Usage: Call this function with temperature, pulse rate, and oxygen saturation values to verify
// if all vital signs are within normal ranges.
int vitalsOk(float temperature, float pulseRate, float spo2) {
    return CheckTemperature(temperature) && CheckPulse(pulseRate) && CheckSPO2(spo2);
}
