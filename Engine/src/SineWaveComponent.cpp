#include "SineWaveComponent.hpp"

SineWaveComponent::SineWaveComponent(double _amplitude, double _sine_length, int _x, int _y, bool _isTravelingRight){
    amplitude = _amplitude;
    sineLength = _sine_length;
    origX = _x;
    origY = _y;
    initX = _x;
    initY = _y;
    travelingRight = _isTravelingRight;
    origianllyTravelingRight = _isTravelingRight;
}
SineWaveComponent::~SineWaveComponent(){}

void SineWaveComponent::UpdateY(GameObject* obj, int x){
    double adjustedX = x - initX;
    double y;
    if (travelingRight) {
        y = amplitude * std::sin((2 * PI / sineLength) * adjustedX) + initY;
    } else {
        y = amplitude * std::sin((2 * PI / sineLength) * (-adjustedX)) + initY;
    }
    // Only update the y velocity
    obj->yVel = static_cast<int>(y) - obj->mTransform->yPos;
}

void SineWaveComponent::changeInitialY(int delta) {
    initY += delta;
}

void SineWaveComponent::changeInitialX(int delta) {
    initX += delta;
}

void SineWaveComponent::reverseDirection() {
    if (travelingRight) {
        travelingRight = false;
        initX += static_cast<int>(sineLength / 2);
    }
    else {
        travelingRight = true;
        initX -= static_cast<int>(sineLength / 2);
    }
}

void SineWaveComponent::restartSineWave(GameObject* obj) {
    travelingRight = origianllyTravelingRight;
    initX = origX;
    initY = origY;
    obj->mTransform->xPos = origX;
    obj->mTransform->yPos = origY;
}

bool SineWaveComponent::isTravelingRight() {
    return travelingRight;
}
