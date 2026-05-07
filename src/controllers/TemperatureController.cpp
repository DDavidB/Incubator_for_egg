#include "TemperatureController.h"

TemperatureController::TemperatureController(IHeater& h)
    : heater(h) {}

void TemperatureController::update(float currentTemp) {
    if (currentTemp < targetTemp) {
        heater.on();
    }
}