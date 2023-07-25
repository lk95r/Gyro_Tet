
#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/i2c.h" 

#include "mpu6050.h"

#define PICO
//#include "mpu6050.h"

// I2C defines
// This example will use I2C0 on GPIO8 (SDA) and GPIO9 (SCL) running at 400KHz.
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define I2C_PORT i2c0


MPU6050 mpu6050;

int main()
{
    stdio_init_all();

    uint8_t error=mpu6050.begin();
    printf(mpu6050.error_str(error));

    sleep_ms(5000);

    while(1){
    
        mpu6050.absent();
        MPU6050_t data= mpu6050.get();
        
        printf("ae= %d, ax= %3.1f, ay= %3.1f, az= %3.1f\n",data.accel.error,data.accel.x,data.accel.y,data.accel.z);
        printf("ge= %d, gx= %3.1f, gy= %3.1f, gz= %3.1f\n",data.gyro.error,data.gyro.x,data.gyro.y,data.gyro.z);
        printf("de= %d, dx= %3.1f, dy= %3.1f, dz= %3.1f\n",data.dir.error,data.dir.roll,data.dir.pitch,data.dir.yaw);
        printf("te= %d, tt= %3.1f\n\n",data.temp.error,data.temp.t);
        
        sleep_ms(1000);
    }
    

    return 0;
}
