#include <cstdio>

class CarbonFootprint {

protected:
    static const int CARBON_MULTIPLIER = 5000;

public:
    virtual double getCarbonFootprint () = 0;
};

class Building : public CarbonFootprint {

public:
    static const int MATERIAL_BATUBATA = 250;
    static const int MATERIAL_CEMENT = 300;
    //......
    
    int mMaterial;
    
    Building (int material) {
        mMaterial = material;
    }
    
    double getCarbonFootprint () {
        return mMaterial * CARBON_MULTIPLIER;
    }
};

class Car : public CarbonFootprint {

public:
    static const int FUEL_PETROL = 500;
    static const int FUEL_DIESEL = 750;
    static const int FUEL_ELECTRIC = 250;
    static const int FUEL_NATURAL_GAS = 100;
    
    int mFuelType;
    long mOdometer;
    
    Car (int fuelType, long odometer) {
        mFuelType = fuelType;
        mOdometer = odometer;
    }
    
    double getCarbonFootprint () {
        return mFuelType * mOdometer * CARBON_MULTIPLIER;
    }
};

class Bicycle : public CarbonFootprint {

public:
    double getCarbonFootprint () {
        return 0.0;
    }
};

int main () {
    Car mobil1 (Car::FUEL_PETROL, 500);
    printf ("%.2lf\n", mobil1.getCarbonFootprint ());
    
    Bicycle sepeda;
    printf ("%.2lf\n", sepeda.getCarbonFootprint ());
    
    Building rumah (Building::MATERIAL_BATUBATA);
    printf ("%.2lf\n", rumah.getCarbonFootprint ());
}