#include <Arduino.h>
#include <MPU6050Controller.h>
#include <ILI9341Controller.h>

constexpr int TFT_CS   = 41;
constexpr int TFT_DC   = 39;
constexpr int TFT_RST  = 40;

constexpr int TFT_MOSI = 38;
constexpr int TFT_MISO = 35;
constexpr int TFT_SCLK = 37;

constexpr int MPU_SDA = 4;
constexpr int MPU_SCL = 5;


ILI9341Controller* display = nullptr;
MPU6050Controller* gyro    = nullptr;

void setup()
{
    Serial.begin(115200);


    display = new ILI9341Controller(
        TFT_CS,
        TFT_RST,
        TFT_DC,
        TFT_MOSI,
        TFT_MISO,
        TFT_SCLK
    );

    gyro = new MPU6050Controller(
        MPU_SDA,
        MPU_SCL
    );

    gyro->begin();
}

constexpr int loopRateCooldown = 200;
void loop()
{
    delay(loopRateCooldown);

    auto eul = gyro->GetEuler();
    Serial.print(eul[0]);   Serial.print(";");
    Serial.print(eul[1]);   Serial.print(";");
    Serial.print(eul[2]);   Serial.println(";");
}