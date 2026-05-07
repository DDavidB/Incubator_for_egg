#pragma once

class IHumiditySensor {
public:
    virtual ~IHumiditySensor() = default;

    virtual double readHumidity() const = 0;
};