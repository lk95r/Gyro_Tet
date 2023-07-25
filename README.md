# Gyro_Test

Just a simple Testproject to test my Port of maarten pennings mpu6050 library.
Currently it uses the I2C-Port: *i2c0* and the Pins *I2C_SDA 8* *I2C_SCL 9*
The library itself is linked as a submodule to this repo.
In order to build the project you have to adjust the path to the pico-sdk in the CMakeLists.txt file in the root folder. And execute the following commands:

Create build folder

>~/Gyro-Tet$ mkdir build

change to build folder

>~/Gyro-Tet$ cd build

setup tmakefile

>~/Gyro-Tet/build$ cmake ..

make and compile project

>~/Gyro-Tet/build$ make
