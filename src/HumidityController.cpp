#include "HumidityController.h"

HumidityController::HumidityController(
    IHumidifier& humidifier,
    IHumiditySensor& sensor)
    : humidifier(humidifier), sensor(sensor)
{
}

void HumidityController::update() {
    if (sensor.readHumidity() < 50.0) {
        humidifier.turnOn();
    }
}