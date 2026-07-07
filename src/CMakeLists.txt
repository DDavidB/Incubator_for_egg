add_library(incubator_core
    Heater.cpp
    IncubatorController.cpp
    HumidityController.cpp
 "interfaces/IHumidifier.h" "interfaces/IHumiditySensor.h" "HumidityController.cpp")

target_include_directories(incubator_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

