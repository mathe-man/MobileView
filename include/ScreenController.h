#pragma once
#include <cstdint>


struct Vec2 {
    float x, y = 0;
};

struct Color {
    float r, g, b = 0;
};

class ScreenController {
public:
    virtual ~ScreenController() = default;

    // Drawings
    virtual void AddPoint(Vec2 pos);
    virtual void AddLine(Vec2 start, Vec2 end) = 0;


    // Color settings
    virtual void SetDrawingColor(Color color);
    virtual void SetBackgroundColor(Color color);

};
