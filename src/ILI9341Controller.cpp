#include <ILI9341Controller.h>

ILI9341Controller::ILI9341Controller(
    int cs_pin,
    int rst_pin,
    int dc_pin,
    int mosi_pin,
    int miso_pin,
    int sclk_pin,
    Color background,
    Color drawing
    )
        : m_spi(FSPI),
      m_tft(&m_spi, dc_pin, cs_pin, rst_pin)
{

    // SPI communication establishment
    m_spi.begin(
        sclk_pin,
        miso_pin,
        mosi_pin
        );


    // TFT Screen init
    m_tft.begin();


    // Default colors
    // White background
    m_backgroundColor   = ToRGB565(background);
    // Black drawing
    m_drawColor         = ToRGB565(drawing);


    // Setup screen
    m_tft.setRotation(0);
    m_tft.fillScreen(m_backgroundColor);
}

uint16_t ILI9341Controller::ToRGB565(const Color &color) {
    return m_tft.color565(
        static_cast<uint8_t>(color.r * 255.f),
        static_cast<uint8_t>(color.g * 255.f),
        static_cast<uint8_t>(color.b * 255.f)
    );
}

void ILI9341Controller::SetDrawColor(const Color &color) {
    m_drawColor = ToRGB565(color);
}

void ILI9341Controller::SetBackground(const Color &color) {
    m_backgroundColor = ToRGB565(color);
}

void ILI9341Controller::DrawPixel(int x, int y) {
    m_tft.drawPixel(x, y, m_drawColor);
}

void ILI9341Controller::DrawLine(int x1, int y1, int x2, int y2) {
    m_tft.drawLine(x1, y1, x2, y2, m_drawColor);
}

void ILI9341Controller::DrawCircle(int x, int y, int radius) {
    m_tft.drawCircle(x, y, radius, m_drawColor);
}

void ILI9341Controller::Clear() {
    m_tft.fillScreen(m_backgroundColor);
}
