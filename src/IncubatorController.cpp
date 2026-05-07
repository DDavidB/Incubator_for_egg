#include "IncubatorController.h"

IncubatorController::IncubatorController(IHeater& heater,
                                         ITemperatureSensor& sensor)
    : heater(heater), sensor(sensor) {}

void IncubatorController::update() {
    double temperature = sensor.readTemperature();

    if (!heaterOn && temperature < LOWER_THRESHOLD) {
        heater.turnOn();
        heaterOn = true;
    }
    else if (heaterOn && temperature > UPPER_THRESHOLD) {
        heater.turnOff();
        heaterOn = false;
    }
}
