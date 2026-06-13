#include <MPU6050Controller.h>

void MPU6050Controller::begin() {
    // Start I2C
    Wire.begin(_sda, _sdl);
    Wire.setClock(400000);

    mpu.initialize();
    delay(100); // Wait for init
    if (!mpu.testConnection()) {
        Serial.println("MPU6050: initialisation failed !");
        while (true) delay(400);
    }


    devStatus = mpu.dmpInitialize();
    // Check status of the dmpt
    if (devStatus != 0) {
        Serial.println("DMP Failed !");
        while (true) delay(400);
    }

    // Calibrate
    Serial.println("MPU6050: Setting everything up... don't move");

    mpu.CalibrateAccel(15);
    mpu.CalibrateGyro(15);

    mpu.setDMPEnabled(true);

    packetSize = mpu.dmpGetFIFOPacketSize();
    dmpReady = true;

    // Clear the FIFO before starting
    mpu.resetFIFO();
    delay(50);

    Serial.println("MPU6050: Successfully initied");
}


float* MPU6050Controller::GetEuler() {

    if (!dmpReady)
        return nullptr;

    // Get the last packet sent by the dmp, if it fails then we return
    if (!mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
        return nullptr;
    }

    // Extract euler angles from the packet
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

    return ypr;

}
