#pragma once

#include "interfaces/IHeater.h"
#include "interfaces/ITemperatureSensor.h"

class IncubatorController {
public:
    IncubatorController(IHeater& heater, ITemperatureSensor& sensor);

    void update();

private:
    static constexpr double LOWER_THRESHOLD = 36.8;
    static constexpr double UPPER_THRESHOLD = 37.2;

    IHeater& heater;
    ITemperatureSensor& sensor;
    bool heaterOn = false;
};
