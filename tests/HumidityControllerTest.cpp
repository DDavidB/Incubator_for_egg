#include <gtest/gtest.h>
#include "interfaces/IHumidifier.h"
#include "interfaces/IHumiditySensor.h"

// Fake Humidifier
class FakeHumidifier : public IHumidifier {
private:
    bool state = false;

public:
    void turnOn() override { state = true; }
    void turnOff() override { state = false; }
    bool isOn() const override { return state; }
};

// Fake Sensor
class FakeHumiditySensor : public IHumiditySensor {
private:
    double humidity;

public:
    FakeHumiditySensor(double h) : humidity(h) {}

    double readHumidity() const override {
        return humidity;
    }

    void setHumidity(double h) {
        humidity = h;
    }
};

#include "HumidityController.h"

TEST(HumidityControllerTest, TurnsOnWhenHumidityIsLow) {
    FakeHumidifier humidifier;
    FakeHumiditySensor sensor(40.0);

    HumidityController controller(humidifier, sensor);
    controller.update();

    EXPECT_TRUE(humidifier.isOn());
}