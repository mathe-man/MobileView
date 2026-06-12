#pragma once

class SpaceController {
public:
    virtual ~SpaceController() = default;

    virtual float* GetEuler() const = 0;
    virtual float* GetXYZ()   const = 0;
};