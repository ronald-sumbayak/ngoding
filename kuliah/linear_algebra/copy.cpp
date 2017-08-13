#include <cstdio>

int main () {
    int size;
    printf ("Masukkan ukuran matriks: ");
    scanf ("%d", &size);
    
    double matriks[size][size*2];
    for (int y = 0; y < size; y++) {
        printf ("Masukkan baris ke-%d:", y+1);
        for (int x = 0; x < size; x++) {
            scanf ("%lf", &matriks[y][x]);
        }
    }
    
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (x == y) matriks[y][x+size] = 1;
            else matriks[y][x+size] = 0;
        }
    }

    printf ("\nMatriks input:\n");
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size*2; x++) {
            printf ("%.2lf\t", matriks[y][x]);
        }
        printf ("\n");
    }
    printf ("\nMatriks inverse:\n");
    
    int arah = 1;
    for (int x = 0; x < size && x >= 0; x+=arah) {
        for (int y = x; y < size && y >= 0; y+=arah) {
            if (x == y) {
                double z;
                z = matriks[y][x];
                
                for (int i = 0; i < size*2; i++) {
                    matriks[y][i] /= z;
                }
            }
            else {
                double z;
                z = matriks[y][x];
                
                for (int i = 0; i < size*2; i++) {
                    matriks[y][i] += ((-z) * matriks[x][i]);
                }
            }
            
            int barisNol = true;
            for (int i = 0; i < size; i++) {
                if (matriks[y][i] != 0) {
                    barisNol = false;
                    break;
                }
            }
            
            if (barisNol) {
                printf ("N/A");
                return 0;
            }
        }
        
        if (x == size-1 && arah != -1) {
            x++;
            arah = -1;
        }
    }
    
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            printf ("%.2lf\t", matriks[y][x+size]);
        }
        printf ("\n");
    }
}