#pragma once


struct Color {
    float r = 1.f;
    float g = 1.f;
    float b = 1.f;
};

class GraphicsController {
public:
    virtual ~GraphicsController() = default;

    virtual void SetDrawColor(const Color& color)           = 0;
    virtual void SetBackground(const Color& color)          = 0;

    virtual void DrawPixel(int x1, int y1)                  = 0;
    virtual void DrawLine(int x1, int y1, int x2, int y2)   = 0;
    virtual void DrawCircle(int x, int y, int radius)       = 0;

    virtual void Clear() = 0;
};