cmake_minimum_required(VERSION 3.14)

project(CPP_SCIENTIFIC_UNITS VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(CTest)
include(FetchContent)
include(Warnings)

FetchContent_Declare(
                    googletest
                    # Specify the commit you depend on and update it regularly.
                    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
                    )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FILE(GLOB SOURCES src/*.cpp)

set(LIBRARY_NAME scientific_units)  # Default name for the library built from src/*.cpp (change if you wish)

add_library(${LIBRARY_NAME} OBJECT ${SOURCES})

target_set_warnings(${LIBRARY_NAME} ENABLE ALL AS_ERROR ALL DISABLE Annoying)

target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/)

include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/include/type_arithmetic)

include_directories(${PROJECT_SOURCE_DIR}/test/include)

enable_testing()

FILE(GLOB TESTFILES test/*.cpp)

set(TEST_MAIN unit_tests)   # Default name for test executable (change if you wish).
add_executable(${TEST_MAIN} ${TESTFILES} ${SOURCES})
target_link_libraries(${TEST_MAIN} gtest_main)
target_set_warnings(${TEST_MAIN} ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).

set_target_properties(${TEST_MAIN} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_test(
    # Use some per-module/project prefix so that it is easier to run only tests for this module
    NAME ${LIBRARY_NAME}.${TEST_MAIN}
    COMMAND ${TEST_MAIN} ${TEST_RUNNER_PARAMS})
