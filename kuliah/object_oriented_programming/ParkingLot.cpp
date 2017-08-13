#include <cstdio>
#include <cstdlib>
#include <vector>
#include <conio.h>
#include <cstring>
#include "Bike.h"
#include "Car.h"

void getParkingLotSize (int*);
void getParkingLotInput (std::vector<Vehicle>&, int*);
void printParkingLotData (std::vector<Vehicle>&);

int main () {
    std::vector<Vehicle> parkingLot;
    int parkingLotSize;
    
    getParkingLotSize (&parkingLotSize);
    getParkingLotInput (parkingLot, &parkingLotSize);
    printParkingLotData (parkingLot);
    getch ();
    
    return 0;
}

void getParkingLotSize (int *size) {
    printf ("Parking Lot Size: ");
    scanf ("%d", size);
    system ("cls");
}

void getParkingLotInput (std::vector<Vehicle>& parkingLot, int *size) {
    Vehicle *newVehicle;
    char *input = new char [25];
    const char *msg[] {
        "Brand", "Type", "License Number", "Color", "Production Year"
    };
    
    for (int x = 0; x < *size; x++) {
        printf ("Vehicle %d\n", x+1);
        printf ("    Vehicle Type: ");
        scanf ("%s", input);
    
        if (strcmp (input, "Bike") == 0) newVehicle = new Bike;
        else if (strcmp (input, "Car") == 0) newVehicle = new Car;
        else {
            x--; continue;
        }
        
        for (int i = 0; i < 5; i++) {
            input = new char [25];
            printf ("    %s: ", msg[i]);
            scanf ("%s", input);
            newVehicle->set (i, input);
        }
        
        parkingLot.insert (parkingLot.end (), *newVehicle);
    }
    
    printf ("\n");
    system ("cls");
}

void printParkingLotData (std::vector<Vehicle>& parkingLot) {
    printf ("----(%d)------\n", parkingLot.size ());
    for (std::size_t x = 0; x < parkingLot.size () ; x++) {
        Vehicle *Vehicle;
        Vehicle = &parkingLot.at (x);
        
        printf ("Vehicle %d:\n", x+1);
        printf ("    Vehicle Type: %s\n", Vehicle->getVehicleType ());
        printf ("    Brand & Type: %s %s\n", Vehicle->getBrand (), Vehicle->getType ());
        printf ("    License Number: %s\n", Vehicle->getLicenseNumber ());
        printf ("    Color: %s\n", Vehicle->getColor ());
        printf ("    Production Year: %s\n", Vehicle->getYear ());
        printf ("\n");
    }
}