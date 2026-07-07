#include "IncubatorController.h"

IncubatorController::IncubatorController(
    IHeater& heater,
    ITemperatureSensor& sensor
)
    : heater(heater), sensor(sensor)
{
}

void IncubatorController::update()
{
    double temperature = sensor.readTemperature();

    if (temperature < 37.5)
    {
        heater.turnOn();
    }
    else
    {
        heater.turnOff();
    }
}