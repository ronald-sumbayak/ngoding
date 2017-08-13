#ifndef OBJECT_ORIENTED_PROGRAMMING_BIKE_H
#define OBJECT_ORIENTED_PROGRAMMING_BIKE_H

#include "Vehicle.h"

class Bike : public Vehicle {

public:
    
    virtual const char *getVehicleType () {
        return "Bike";
    }
};

#endif //OBJECT_ORIENTED_PROGRAMMING_BIKE_H
