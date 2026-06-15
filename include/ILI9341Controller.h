#pragma once

#include <ScreenController.h>

// Platformio lib_deps =
// lovyan03/LovyanGFX
#include <LovyanGFX.hpp>

struct Pinout {
    uint16_t pin_cs;
    uint16_t pin_reset;
    uint16_t pin_dc;
    uint16_t pin_mosi;
    uint16_t pin_SCK;
    uint16_t pin_miso;
};

class ILI9341Controller : public ScreenController, public lgfx::LGFX_Device {
    lgfx::Panel_ILI9341 _panel_instance;
    lgfx::Bus_SPI       _bus_instance;


public:
    ILI9341Controller(Pinout pins, uint16_t width = 240, uint16_t height = 320, uint32_t freq_write = 40000000, uint32_t freq_read = 16000000);

    virtual ~ILI9341Controller() =  default;

    void begin() { init(); }

    // TODO implement the ScreenController methods
};