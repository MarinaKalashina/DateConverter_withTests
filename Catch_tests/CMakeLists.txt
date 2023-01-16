
find_package(Catch2 3 REQUIRED)
add_executable(Catch_tests_run AbsoluteDateTest.cpp ConverterTests.cpp)

target_link_libraries(Catch_tests_run PRIVATE DateConverter_lib)
target_link_libraries(Catch_tests_run PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(Catch_tests_run)

