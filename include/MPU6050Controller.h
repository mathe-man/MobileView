#pragma once

#include <SpaceController.h>

#include <Wire.h>
#include <I2Cdev.h>

// Platformio lib_deps =
// electroniccats/MPU6050
#include <MPU6050_6Axis_MotionApps20.h>


class MPU6050Controller : public SpaceController {
public:
    MPU6050Controller(int pinSDA, int pinSDL) {
        _sda = pinSDA;
        _sdl = pinSDL;
    }

    ~MPU6050Controller() {
    }

    void begin();

    float* GetEuler() override;
    float* GetXYZ() override {
        // TODO implement
        return  nullptr;
    }

private:
    // pins
    int _sda;
    int _sdl;

    MPU6050 mpu; // mpu object

    // DMP Control vars
    bool dmpReady = false;
    uint8_t devStatus;
    uint16_t packetSize;
    uint8_t fifoBuffer[64];

    Quaternion q;
    VectorFloat gravity;

    float ypr[3]; // Yaw, pitch, roll
};