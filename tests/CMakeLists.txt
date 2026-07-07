add_executable(runTests
    HeaterTest.cpp
    IncubatorControllerTest.cpp
    HumidityControllerTest.cpp
)

target_link_libraries(runTests
    incubator_core
    gtest
    gtest_main
)

add_test(NAME AllTests COMMAND runTests)