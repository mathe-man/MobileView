#pragma once

class SpaceController {
public:
    virtual ~SpaceController() = default;

    virtual float* GetEuler() = 0;
    virtual float* GetXYZ() = 0;
};