#include <gtest/gtest.h>
#include "IncubatorController.h"
#include "interfaces/IHeater.h"
#include "interfaces/ITemperatureSensor.h"

class FakeHeater : public IHeater {
private:
    bool state = false;

public:
    void turnOn() override { state = true; }
    void turnOff() override { state = false; }
    bool isOn() const override { return state; }
};

class FakeTemperatureSensor : public ITemperatureSensor {
public:
    explicit FakeTemperatureSensor(double temp) : temperature(temp) {}

    double readTemperature() const override {
        return temperature;
    }

    void setTemperature(double t) {
        temperature = t;
    }

private:
    double temperature;
};

TEST(IncubatorControllerTest, TurnsHeaterOnWhenTemperatureIsLow) {
    FakeHeater heater;
    FakeTemperatureSensor sensor(36.5);

    IncubatorController controller(heater, sensor);
    controller.update();

    EXPECT_TRUE(heater.isOn());
}

TEST(IncubatorControllerTest, TurnsHeaterOffWhenTemperatureIsHigh) {
    FakeHeater heater;
    FakeTemperatureSensor sensor(38.0);

    IncubatorController controller(heater, sensor);
    controller.update();

    EXPECT_FALSE(heater.isOn());
}

TEST(IncubatorControllerTest, KeepsHeaterOnInsideSafeRange) {
    FakeHeater heater;
    FakeTemperatureSensor sensor(36.5);

    IncubatorController controller(heater, sensor);

    controller.update();

    EXPECT_TRUE(heater.isOn());

    sensor.setTemperature(37.6);
    controller.update();

    EXPECT_TRUE(heater.isOn());
}