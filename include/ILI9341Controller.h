#pragma once
#include <GraphicsController.h>

#include <SPI.h>
#include <Adafruit_ILI9341.h>

class ILI9341Controller : public GraphicsController {
public:
    ILI9341Controller(
        int cs_pin, int rst_pin, int dc_pin,
        int mosi_pin, int miso_pin, int sclk_pin,
        Color background = {1.f, 1.f, 1.f},
        Color drawing = {0.f, 0.f, 0.f}
        );


    void SetDrawColor(const Color &color) override;
    void SetBackground(const Color &color) override;

    void DrawPixel(int x, int y) override;
    void DrawLine(int x1, int y1, int x2, int y2) override;
    void DrawCircle(int x, int y, int radius) override;

    void Clear() override;
private:
    SPIClass m_spi;
    Adafruit_ILI9341 m_tft;

    // This screen use RGB565 color parameters
    uint16_t inline ToRGB565(const Color& color);
    uint16_t m_drawColor;
    uint16_t m_backgroundColor;
};