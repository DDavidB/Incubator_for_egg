#define CATCH_CONFIG_MAIN
#include "../external/Catch2/extras/catch_amalgamated.hpp"

#include "../src/controllers/TemperatureController.h"
#include "../mocks/MockHeater.h"

TEST_CASE("Heater turns ON when temperature is below target") {
    MockHeater heater;
    TemperatureController controller(heater);

    controller.update(36.8f);

    REQUIRE(heater.isOn() == true);
}
