#pragma once

#include "interfaces/IHeater.h"
#include "interfaces/ITemperatureSensor.h"

class IncubatorController {
private:
    IHeater& heater;
    ITemperatureSensor& sensor;

public:
    IncubatorController(IHeater& heater, ITemperatureSensor& sensor);

    void update();
};