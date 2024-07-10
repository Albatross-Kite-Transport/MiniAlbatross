#include <Arduino.h>
#include "State.h"



void Kite::updateAngle(){
    Quaternion conjugate = this->orientation.getNormalized().getConjugate();
    VectorFloat unitVector(0, 0, -1);
    unitVector.rotate(&conjugate);

    this->angle = -atan2f(unitVector.y, unitVector.x) * RAD_TO_DEG;;
}

void Kite::updatePosition(){
    orientation = this->orientation;
    VectorFloat wire(0, 0, 1);

    // normalize the positional quaternion, so we can use it to multiply
    orientation.normalize();
    
    wire.rotate(&orientation);

    this->position = wire;
}

void Kite::update(){
    this->updatePosition();
    this->updateAngle();
}


void State::update(){
    this->kite.update();
}

State state;
