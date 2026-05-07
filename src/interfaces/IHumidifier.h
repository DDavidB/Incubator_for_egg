#pragma once

class IHumidifier {
public:
    virtual ~IHumidifier() = default;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool isOn() const = 0;
};