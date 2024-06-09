#ifndef SINEWAVECOMPONENT_HPP
#define SINEWAVECOMPONENT_HPP

#include "GameObject.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>

class GameObject;

class SineWaveComponent {
    public:
        SineWaveComponent(double _amplitude, double _sine_length, int _x, int _y, bool _isTravelingRight);
        ~SineWaveComponent();
        void UpdateY(GameObject* obj, int x);
        void changeInitialY(int delta);
        void changeInitialX(int delta);
        void reverseDirection();
        void restartSineWave(GameObject* obj);
        bool isTravelingRight();

    private:
        double amplitude;
        double sineLength;
        int initX;
        int initY;
        bool travelingRight;
        int origX;
        int origY;
        bool origianllyTravelingRight;
        const double PI = 3.14159265358979323846;
};


#endif