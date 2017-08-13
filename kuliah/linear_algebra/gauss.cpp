#include <cstdio>
#include <conio.h>

class GaussJordan {
    bool mStep;
    int mVariable;
    double **mMatrix;

public:
    void getMatrixSize () {
        printf ("Masukkan jumlah variable: ");
        scanf ("%d", &mVariable);
    }

    void setupMatrix () {
        mMatrix = new double *[mVariable];

        for (int x = 0; x < mVariable; x++) {
            mMatrix[x] = new double [mVariable + 1];
        }
    }

    void getUserInput () {
        for (int y = 0; y < mVariable; y++) {
            printf ("Masukkan PL%d: ", y + 1);

            for (int x = 0; x < mVariable + 1; x++) {
                scanf ("%lf", &mMatrix[y][x]);
            }
        }
    }

    void solve () {
        int direction = 1;

        for (int x = 0; x < mVariable && x >= 0; x+=direction) {
            for (int y = x; y < mVariable && y >= 0; y+=direction) {
                if (x == y) leadingOne (y);
                else zeroElement (y, x);

                if (mStep) printMatrix ();
            }

            if (x == mVariable - 1 && direction != -1) {
                direction = -1;
                x++;
            }
        }
    }

    /** set leading-one to one **/
    void leadingOne (int row) {
        double leader = mMatrix[row][row];

        for (int x = 0; x < mVariable + 1; x++) {
            mMatrix[row][x] /= leader;
        }
    }

    /** set matrice element to zero **/
    void zeroElement (int row, int column) {
        double leader = mMatrix[row][column];

        for (int x = 0; x < mVariable + 1; x++) {
            mMatrix[row][x] += (-leader * mMatrix[column][x]);
        }
    }

    void printMatrix (int mode = 0) {
        if (mode == 1) printf ("\nAugmented Matrix:\n");
        else if (mode == 2) printf ("\nMatriks Eselon Baris Tereduksi:\n");
        else printf ("------------------------------\n");

        for (int y = 0; y < mVariable; y++) {
            for (int x = 0; x < mVariable + 1; x++) {
                printf ("%g\t", mMatrix[y][x]);
            }

            printf ("\n");
        }

        if (mode == 1 && mStep) printf ("\nsteps:\n");
    }

    void printSolution () {
        printf ("\nSolution:\n");

        for (int x = 0; x < mVariable; x++) {
            printf ("x%d: %g\n", x+1, mMatrix[x][mVariable]);
        }
    }

    void promptStepPrint () {
        getchar ();
        printf ("print setiap step (Y/N) ?");
        char stepChoice;
        scanf ("%c", &stepChoice);

        mStep = stepChoice == 'y' || stepChoice == 'Y';
    }
};

int main () {
    GaussJordan gaussJordan;
    gaussJordan.getMatrixSize ();
    gaussJordan.setupMatrix ();
    gaussJordan.getUserInput ();
    gaussJordan.promptStepPrint ();
    gaussJordan.printMatrix (1);
    gaussJordan.solve ();
    gaussJordan.printMatrix (2);
    gaussJordan.printSolution ();

    getch ();
    return 0;
}