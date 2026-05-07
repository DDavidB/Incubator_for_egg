#include "Heater.h"

void Heater::turnOn() {
    on = true;
}

void Heater::turnOff() {
    on = false;
}

bool Heater::isOn() const {
    return on;
}
