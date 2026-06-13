#include <Arduino.h>
#include <MPU6050Controller.h>

MPU6050Controller mpu(4, 5);

void setup() {
    Serial.begin(115200);
    mpu.begin();
}

void loop() {
    auto eul = mpu.GetEuler();

    if (!eul)
        return;


    Serial.print(eul[0], 10);   Serial.print(";");
    Serial.print(eul[1], 10);   Serial.print(";");
    Serial.print(eul[2], 10);   Serial.println(";");
}