#include <cstdio>
#include <conio.h>
#include <cstdlib>

struct Tamagotchi {
    const char *name;
    int stamina;
    int health;
    int happiness;
    
    Tamagotchi (const char *name) {
        this->name = name;
        stamina = health = happiness = 100;
    }
};

void doAction (Tamagotchi *tama, int action);
void play (Tamagotchi *tama);
void feed (Tamagotchi *tama);
void sleep (Tamagotchi *tama);
void cuddle (Tamagotchi *tama);
void kill (Tamagotchi *tama);
void displayStats (Tamagotchi tama);
void checkStatus (Tamagotchi tama);
void keepInBound (int *stat);

const char *getPetName ();
void printHeader ();
void printMenu ();

int main () {
    printf ("Welcome :)\n");
    Tamagotchi tama (getPetName ());
    system ("cls");
    
    while (tama.health > 0 && tama.stamina > 0) {
        int choice;
        do {
            printHeader ();
            displayStats (tama);
            checkStatus (tama);
            printMenu ();
            
            choice = getch () - '0';
            system ("cls");
        }
        while (!(choice >= 1 && choice <= 5));
        
        system ("cls");
        doAction (&tama, choice);
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

void doAction (Tamagotchi *tama, int action) {
    switch (action) {
        case 1: play (tama); break;
        case 2: feed (tama); break;
        case 3: sleep (tama); break;
        case 4: cuddle (tama); break;
        case 5: kill (tama); break;
        default: break;
    }
    
    if (!(action == 1 || action == 4)) {
        tama->happiness -= 15;
        keepInBound (&tama->happiness);
    }
}

void play (Tamagotchi *tama) {
    tama->happiness += 10;
    tama->health -= 10;
    tama->stamina -= 10;
    
    keepInBound (&tama->happiness);
    keepInBound (&tama->health);
    keepInBound (&tama->stamina);
}

void feed (Tamagotchi *tama) {
    tama->health += 20;
    tama->stamina += 10;
    
    keepInBound (&tama->health);
    keepInBound (&tama->stamina);
}

void sleep (Tamagotchi *tama) {
    tama->stamina += 50;
    keepInBound (&tama->stamina);
}

void cuddle (Tamagotchi *tama) {
    tama->happiness += 10;
    keepInBound (&tama->happiness);
}

void kill (Tamagotchi *tama) {
    tama->health = tama->stamina = 0;
}

void displayStats (Tamagotchi tama) {
    printf ("Pet name: %s\n", tama.name);
    printf ("Health: %d\n", tama.health);
    printf ("Stamina: %d\n", tama.stamina);
    printf ("Happiness: %d\n", tama.happiness);
    printf ("\n");
}

void checkStatus (Tamagotchi tama) {
    if (tama.health <= 10) printf ("\n !! Your pet is hungry. !!\n");
    if (tama.happiness <= 10) printf ("\n !! Your pet is bored. !!\n");
    if (tama.stamina <= 10) printf ("\n !! Your pet is tired. !!\n");
}

void keepInBound (int *stat) {
    if (*stat < 0) *stat = 0;
    else if (*stat > 100) *stat = 100;
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

