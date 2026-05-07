#pragma once

#include "interfaces/IHumidifier.h"
#include "interfaces/IHumiditySensor.h"

class HumidityController {
private:
    IHumidifier& humidifier;
    IHumiditySensor& sensor;

public:
    HumidityController(IHumidifier& humidifier,
        IHumiditySensor& sensor);

    void update();
};