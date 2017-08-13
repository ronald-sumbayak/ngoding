#include <cstdio>

int jagung (int tunas, int dewasa1, int dewasa2, int subur, int day) {
    if (day == 1) {
        return tunas + dewasa1 + dewasa2 + subur;
    }
    else {
        int born;
        born = (subur * 3) + dewasa1 + dewasa2;
        
        return jagung (born, tunas, dewasa1, (subur + dewasa2), (day - 1));
    }
}

int main () {
    int day;
    scanf ("%d", &day);
    printf ("%d\n", jagung (1, 0, 0, 0, 1, day));
}