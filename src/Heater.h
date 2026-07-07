#pragma once

#include "interfaces/IHeater.h"

class Heater : public IHeater {
public:
    void turnOn() override;
    void turnOff() override;
    bool isOn() const override;

private:
    bool on = false;
};
