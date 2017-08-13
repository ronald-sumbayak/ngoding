#include <cstdio>

class Invoice {
    
    const char *mNumber, *mDescription;
    int mPrice, mQuantity;

public:
    
    Invoice (const char *number, const char *description, int price, int quantity) {
        mNumber = number;
        mDescription = description;
        mPrice = price >= 0 ? price : 0;
        mQuantity = quantity >= 0 ? quantity : 0;
    }
    
    void setNumber (const char *number) {
        mNumber = number;
    }
    
    void setDescription (const char *description) {
        mDescription = description;
    }
    
    void setPrice (int price) {
        mPrice = price >= 0 ? price : 0;
    }
    
    void setQuantity (int quantity) {
        mQuantity = quantity >= 0 ? quantity : 0;
    }
    
    const char *getNumber () {
        return mNumber;
    }
    
    const char *getDescription () {
        return mDescription;
    }
    
    int getPrice () {
        return mPrice;
    }
    
    int getQuantity () {
        return mQuantity;
    }
    
    int getInvoiceAmount () {
        return mPrice * mQuantity;
    }
};

int main () {
    Invoice laptop ("L01", "Laptop", 8500000, 3);
    
    printf ("Initial value:\n");
    printf ("Number: %s\n", laptop.getNumber ());
    printf ("Description: %s\n", laptop.getDescription ());
    printf ("Price: %d\n", laptop.getPrice ());
    printf ("Quantity: %d\n", laptop.getQuantity ());
    printf ("Invoice amount: %d\n", laptop.getInvoiceAmount ());
    
    laptop.setNumber ("L02");
    laptop.setDescription ("Lepi");
    laptop.setPrice (7000000);
    laptop.setQuantity (2);
    
    printf ("\nNew value:\n");
    printf ("Number: %s\n", laptop.getNumber ());
    printf ("Description: %s\n", laptop.getDescription ());
    printf ("Price: %d\n", laptop.getPrice ());
    printf ("Quantity: %d\n", laptop.getQuantity ());
    printf ("Invoice amount: %d\n", laptop.getInvoiceAmount ());
}