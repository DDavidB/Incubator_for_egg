#include "TemperatureController.h"

TemperatureController::TemperatureController(IHeater& h)
    : heater(h) {}

void TemperatureController::update(float currentTemp) {
    if (currentTemp < targetTemp - hysteresis) {
        heater.turnOn();
    } else if (currentTemp > targetTemp + hysteresis) {
        heater.turnOff();
    }
}