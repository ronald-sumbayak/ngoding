#include <cstdio>
#include <conio.h>

class Matrix {
public:
    
    int mHeight, mWidth;
    double **mMatrix;
    
    Matrix (int heigth, int width) {
        mHeight = heigth;
        mWidth = width;
        
        mMatrix = new double *[mHeight];
        
        for (int x = 0; x < mHeight; x++) {
            mMatrix[x] = new double [mWidth];
        }
    }

    void inputElement () {
        for (int y = 0; y < mHeight; y++) {
            printf ("Masukkan baris-%d: ", y+1);
            
            for (int x = 0; x < mWidth; x++) {
                scanf ("%lf", &mMatrix[y][x]);
            }
        }
    }

    bool isZeroRow (int row) {
        for (int x = 0; x < mHeight; x++) {
            if (mMatrix[row][x] != 0) {
                return false;
            }
        }
        
        return true;
    }
    
    void print () {
        for (int y = 0; y < mHeight; y++) {
            for (int x = 0; x < mWidth; x++) {
                if (x == mHeight) printf ("\t|");
                printf ("\t%.2lf", mMatrix[y][x]);
            }
            
            printf ("\n");
        }

        printf ("\n");
    }
};

class GaussJordan {

    static void setOne (Matrix *matrix, int row) {
        double leader = matrix->mMatrix[row][row];
        
        for (int x = 0; x < matrix->mWidth; x++) {
            matrix->mMatrix[row][x] /= leader;
        }
    }

    static void setZero (Matrix *matrix, int row, int column) {
        double leader = matrix->mMatrix[row][column];
        
        for (int x = 0; x < matrix->mWidth; x++) {
            matrix->mMatrix[row][x] += ((-leader) * matrix->mMatrix[column][x]);
        }
    }

public:
    
    static void ero (Matrix *matrix) {
        int direction = 1;

        for (int x = 0; x < matrix->mHeight && x >= 0; x+=direction) {
            for (int y = x; y < matrix->mHeight && y >= 0; y+=direction) {
                if (x == y) setOne (matrix, y);
                else setZero (matrix, y, x);

                matrix->print ();
                
                if (matrix->isZeroRow (y)) {
                    return;
                }

            }

            if (x == matrix->mWidth - 4 && direction != -1) {
                direction = -1;
                x++;
            }
        }
    }
};

class Inverse {
    
public:
    
    static void expandMatrix (Matrix *matrix) {
        double **newMatrix;
        newMatrix = new double *[matrix->mHeight];
        for (int x = 0; x < matrix->mHeight; x++) newMatrix[x] = new double [matrix->mWidth * 2];
        
        for (int y = 0; y < matrix->mHeight; y++) {
            for (int x = 0; x < matrix->mWidth; x++) {
                newMatrix[y][x] = matrix->mMatrix[y][x];
            }
        }
        
        for (int y = 0; y < matrix->mHeight; y++) {
            for (int x = 0; x < matrix->mWidth; x++) {
                if (x == y) {
                    newMatrix[y][x + matrix->mWidth] = 1;
                }
                else {
                    newMatrix[y][x + matrix->mWidth] = 0;
                }
            }
        }

        matrix->mWidth *= 2;
        matrix->mMatrix = newMatrix;
    }
    
    static void reverse (Matrix *matrix) {
        for (int y = 0; y < matrix->mHeight; y++) {
            for (int x = 0; x < matrix->mWidth; x++) {
                matrix->mMatrix[y][x] = matrix->mMatrix[y][x + matrix->mHeight];
            }
        }
        
        matrix->mWidth = matrix->mHeight;
    }

    static void printInverse (Matrix matrix) {
        for (int x = 0; x < matrix.mHeight; x++) {
            if (matrix.isZeroRow (x)) {
                printf ("N/A");
                return;
            }
        }

        reverse (&matrix);
        matrix.print ();
    }
};

int main () {
    int size;
    printf ("Masukkan ukuran matriks: ");
    scanf ("%d", &size);
    
    Matrix matrix (size, size);
    printf ("\n");
    matrix.inputElement ();
    
    printf ("\n");
    printf ("Matriks Input:\n");
    matrix.print ();
    
    Inverse::expandMatrix (&matrix);
    GaussJordan::ero (&matrix);
    
    printf ("Matrix Inverse:\n");
    Inverse::printInverse (matrix);
    
    getch ();
    return 0;
}