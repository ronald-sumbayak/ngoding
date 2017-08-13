#include <cstdio>
#include <cstdlib>
#include <conio.h>

class Tamagotchi {
    
    const char *mName;
    int mStamina;
    int mHealth;
    int mHappiness;
    
public:
    
    Tamagotchi (const char *name) {
        mName = name;
        mHappiness = mHealth = mStamina = 100;
    }
    
    void doAction (int action) {
        switch (action) {
            case 1: play (); break;
            case 2: feed (); break;
            case 3: sleep (); break;
            case 4: cuddle (); break;
            case 5: kill (); break;
            default: break;
        }
        
        if (!(action == 1 || action == 4)) {
            mHappiness -=15;
            keepInBound (&mHappiness);
        }
    }
    
    void play () {
        mHappiness += 10;
        mHealth -= 10;
        mStamina -= 10;
        
        keepInBound (&mHappiness);
        keepInBound (&mHealth);
        keepInBound (&mStamina);
    }
    
    void feed () {
        mHealth += 20;
        mStamina += 10;
        
        keepInBound (&mHealth);
        keepInBound (&mStamina);
    }
    
    void sleep () {
        mStamina += 50;
        keepInBound (&mStamina);
    }
    
    void cuddle () {
        mHappiness += 10;
        keepInBound (&mHappiness);
    }
    
    void kill () {
        mHealth = mStamina = 0;
    }
    
    bool isAlive () {
        return mHealth > 0 && mStamina > 0;
    }
    
    void displayStats () {
        printf ("Pet Name: %s\n", mName);
        printf ("Health: %d\n", mHealth);
        printf ("Stamina: %d\n", mStamina);
        printf ("Happiness: %d\n", mHappiness);
        printf ("\n");
    }
    
    void checkStatus () {
        if (mHealth <= 10) printf ("\n !! Your pet is hungry. !!\n");
        if (mHappiness <= 10) printf ("\n !! Your pet is bored. !!\n");
        if (mStamina <= 10) printf ("\n !! Your pet is tired. !!\n");
    }
    
    void keepInBound (int *stat) {
        if (*stat < 0) *stat = 0;
        else if (*stat > 100) *stat = 100;
    }
};

const char *getPetName ();
void printHeader ();
void printMenu ();

int main () {
    printf ("Welcome :)\n");
    Tamagotchi tama (getPetName ());
    system ("cls");
    
    while (tama.isAlive ()) {
        int choice;
        do {
            printHeader ();
            tama.displayStats ();
            tama.checkStatus ();
            printMenu ();
            
            choice = getch () - '0';
            system ("cls");
        }
        while (!(choice >= 1 && choice <= 5));
        
        system ("cls");
        tama.doAction (choice);
    }
    
    printf ("\n");
    printf ("Your pet is die. Now get the f*ck out of here!\n\n");
    system ("pause");
}

const char *getPetName () {
    char *name = new char [50];
    printf ("Masukkan nama pet: ");
    scanf ("%[^\n]s", name);
    return name;
}

void printHeader () {
    printf ("-----------------------\n");
    printf (" Text-based Tamagotchi \n");
    printf ("-----------------------\n");
    printf ("\n");
}

void printMenu () {
    printf ("1. Play                \n");
    printf ("2. Feed                \n");
    printf ("3. Sleep               \n");
    printf ("4. Cuddle              \n");
    printf ("5. Kill it             \n");
    printf ("-----------------------\n");
    printf ("Choice: ");
}
