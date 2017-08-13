#ifndef OBJECT_ORIENTED_PROGRAMMING_CAR_H
#define OBJECT_ORIENTED_PROGRAMMING_CAR_H

class Car : public Vehicle {

public:
    
    virtual const char *getVehicleType () {
        return "Car";
    }
};

#endif //OBJECT_ORIENTED_PROGRAMMING_CAR_H
