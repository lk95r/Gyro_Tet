# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/lka/pico/pico-sdk")

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(Gyro_Tet C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

set(PICO_CXX_ENABLE_RTTI 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()



# Add executable. Default name is the project name, version 0.1

add_executable(Gyro_Tet Gyro_Tet.cpp )

pico_set_program_name(Gyro_Tet "Gyro_Tet")
pico_set_program_version(Gyro_Tet "0.1")

pico_enable_stdio_uart(Gyro_Tet 1)
pico_enable_stdio_usb(Gyro_Tet 0)

# Add the standard library to the build
target_link_libraries(Gyro_Tet
        pico_stdlib
        )


# Add my Library
#FILE(GLOB lka_test test_lib_lka)
#add_library(test_lib_lka STATIC 
#            ${lka_test}/test_lib_lka.c 
#            ${lka_test}/test_lib_lka.h) 

#FILE(GLOB MPU MPU6050-pico/src)
#add_library(mpu6050 STATIC
#            ${MPU}/mpu6050.h
#             ${MPU}/mpu.cpp)
#include_directories(test_lib_lka/
#                    ${MPU}/)
#link_directories(test_lib_lka/
#                    ${MPU}/)

# Add the standard include files to the build
target_include_directories(Gyro_Tet PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
  #${CMAKE_CURRENT_LIST_DIR}/test_lib_lka
  ${CMAKE_CURRENT_LIST_DIR}/MPU6050-pico/src
)

add_subdirectory("MPU6050-pico")
# Add any user requested libraries
target_link_libraries(Gyro_Tet 
        hardware_i2c
        #test_lib_lka
        mpu6050
        )

pico_add_extra_outputs(Gyro_Tet)

