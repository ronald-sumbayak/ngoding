//
// Created by Ronald on 07/10/2016.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_VEHICLE_H
#define OBJECT_ORIENTED_PROGRAMMING_VEHICLE_H

class Vehicle {
    
    const char *mBrand, *mType, *mLicense, *mColor, *mYear;

protected:
    
    Vehicle () {
        mBrand = new char [25];
        mType = new char [25];
        mLicense = new char [15];
        mColor = new char [10];
        mYear = new char [5];
    }
    
public:
    
    void set (int i, const char *input) {
        switch (i) {
            case 0: setBrand (input); break;
            case 1: setType (input); break;
            case 2: setLicense (input); break;
            case 3: setColor (input); break;
            case 4: setYear (input); break;
            default: break;
        }
    };
    
    void setBrand (const char *brand) { mBrand = brand; }
    void setType (const char *type) { mType = type; }
    void setLicense (const char *license) { mLicense = license; }
    void setColor (const char *color) { mColor = color; }
    void setYear (const char *year) { mYear = year; }
    
    virtual const char *getVehicleType () {
        
    }
    
    const char *getBrand () { return mBrand; }
    const char *getType () { return mType; }
    const char *getLicenseNumber () { return mLicense; }
    const char *getColor () { return mColor; }
    const char *getYear () { return mYear; }
};

#endif //OBJECT_ORIENTED_PROGRAMMING_VEHICLE_H
