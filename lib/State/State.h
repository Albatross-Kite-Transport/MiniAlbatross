#ifndef State_h
#define State_h

#include <helper_3dmath.h>
#include <math.h>

class Kite{ // TODO: should be struct
    public:
        VectorFloat position;
        float angle; //using axis-angle representation

        Quaternion orientation;
        float wireLength = 50;
        float setpoint = 90; // wanted angle in degrees
        void update();
    private:
        void updateAngle();
        void updatePosition();
};

struct Motor{
    float percentage = 0.0; // percentage of the max input voltage
    float filtered_percentage = 0.0;
    int step = 0; // number of coil steps. TODO: how many steps is one rotation? and what is the diameter?
    float rotation = 0.0; // total rotation
    float speed = 0.0; // rotational velocity
    float current = 0.0;
    bool reverse = false;
};

class State{
    public:
        Kite kite;
        std::array<Motor, 3> motors{Motor(), Motor(), Motor()}; // middle, left, right motor

        float voltage;
        unsigned long start_time = millis();
        unsigned long last_receive_time = micros();
        bool enable = false;
        
        void update();
};


// Global state data structure
extern State state;

#endif
