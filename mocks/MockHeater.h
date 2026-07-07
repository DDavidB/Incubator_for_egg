#pragma once

#include "../src/interfaces/IHeater.h"

class MockHeater : public IHeater {
public:
    void turnOn() override {
        state = true;
    }

    void turnOff() override {
        state = false;
    }

    bool isOn() const override {
        return state;
    }

private:
    bool state = false;
};
