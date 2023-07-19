#include <iostream>
#include <wiringPi.h>
#include "MPU6050.h"

#define ACCEL_XOUT_H 0x3B
#define ACCEL_YOUT_H 0x3D
#define ACCEL_ZOUT_H 0x3F
#define GYRO_XOUT_H  0x43
#define GYRO_YOUT_H  0x45
#define GYRO_ZOUT_H  0x47

int main() {
    float acceleration_x, acceleration_y, acceleration_z;
    float gyro_x, gyro_y, gyro_z;
    float ax = 0, ay = 0, az = 0;
    float gx = 0, gy = 0, gz = 0;

    wiringPiSetup();
    MPU6050 mpu6050(0x68);
    mpu6050.Initialize();

    while (true) {
        acceleration_x = mpu6050.ReadRawData(ACCEL_XOUT_H);
        acceleration_y = mpu6050.ReadRawData(ACCEL_YOUT_H);
        acceleration_z = mpu6050.ReadRawData(ACCEL_ZOUT_H);

        gyro_x = mpu6050.ReadRawData(GYRO_XOUT_H);
        gyro_y = mpu6050.ReadRawData(GYRO_YOUT_H);
        gyro_z = mpu6050.ReadRawData(GYRO_ZOUT_H);

        ax = acceleration_x / 16384.0;
        ay = acceleration_y / 16384.0;
        az = acceleration_z / 16384.0
