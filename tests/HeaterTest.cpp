#include <cassert>
#include "Heater.h"

int main() {
    Heater heater;

    heater.turnOn();
    assert(heater.isOn() && "Heater should be ON after turnOn()");

    heater.turnOff();
    assert(!heater.isOn() && "Heater should be OFF after turnOff()");

    return 0;
}
