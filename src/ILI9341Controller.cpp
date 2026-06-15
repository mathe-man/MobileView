#include <ILI9341Controller.h>

ILI9341Controller::ILI9341Controller(Pinout pins, uint16_t width, uint16_t height, uint32_t freq_write, uint32_t freq_read) {

    // SPI bus configuration
    {
        auto cfg = _bus_instance.config();
        cfg.spi_host = SPI2_HOST;   // FSPI bus of the ESP32-S3
        cfg.spi_mode = 0;
        cfg.freq_write = freq_write;
        cfg.freq_read  = freq_read;
        cfg.pin_sclk = pins.pin_SCK;            // PINS
        cfg.pin_mosi = pins.pin_mosi;
        cfg.pin_miso = pins.pin_miso;
        cfg.pin_dc   = pins.pin_dc;
        _bus_instance.config(cfg);
        _panel_instance.setBus(&_bus_instance);
    }

    // Screen panel configuration
    {
        auto cfg = _panel_instance.config();
        cfg.pin_cs           = pins.pin_cs;
        cfg.pin_rst          = pins.pin_reset;
        cfg.pin_busy         = -1;
        cfg.panel_width      = width;
        cfg.panel_height     = height;
        cfg.offset_x         = 0;
        cfg.offset_y         = 0;
        cfg.rgb_order        = false;
        _panel_instance.config(cfg);
    }

    setPanel(&_panel_instance);
}
