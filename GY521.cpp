#include "MPU6050.h"
#include <wiringPiI2C.h>

#define PWR_MGMT_1   0x6B
#define SMPLRT_DIV   0x19
#define CONFIG       0x1A
#define GYRO_CONFIG  0x1B
#define INT_ENABLE   0x38

MPU6050::MPU6050(int deviceAddress) : device_file_descriptor_(wiringPiI2CSetup(deviceAddress)) {}

void MPU6050::Initialize() {
    wiringPiI2CWriteReg8(device_file_descriptor_, SMPLRT_DIV, 0x07);
    wiringPiI2CWriteReg8(device_file_descriptor_, PWR_MGMT_1, 0x01);
    wiringPiI2CWriteReg8(device_file_descriptor_, CONFIG, 0);
    wiringPiI2CWriteReg8(device_file_descriptor_, GYRO_CONFIG, 24);
    wiringPiI2CWriteReg8(device_file_descriptor_, INT_ENABLE, 0x01);
}

short MPU6050::ReadRawData(int registerAddress) {
    short high_byte, low_byte, value;
    high_byte = wiringPiI2CReadReg8(device_file_descriptor_, registerAddress);
    low_byte = wiringPiI2CReadReg8(device_file_descriptor_, registerAddress + 1);
    value = (high_byte << 8) | low_byte;
    return value;
}
