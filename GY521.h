#ifndef MPU6050_H
#define MPU6050_H

class MPU6050 {
public:
    explicit MPU6050(int deviceAddress);
    void Initialize();
    short ReadRawData(int registerAddress);

private:
    int device_file_descriptor_;
};

#endif // MPU6050_H
