#include <cstdio>
#include <conio.h>

class Matrix {

    double **mMatrix;
    int mHeight, mWidth;
    
public:

    Matrix (int height, int width) {
        mHeight = height;
        mWidth = width;

        mMatrix = new double *[mHeight];
        for (int x = 0; x < mHeight; x++) mMatrix[x] = new double [mWidth];
    }
    
    void set (int x, int y, double value) {
        mMatrix[y][x] = value;
    }
    
    double get (int x, int y) {
        return mMatrix[y][x];
    }
    
    int getHeight () {
        return mHeight;
    }
    
    int getWidth () {
        return mWidth;
    }
    
    /**
     * Calculate determinant of the Matrix in Lower Triangular form
     * @return determinant of the Matrix
     */
    double calculateDeterminant () {
        double determinant = 1.0;
        
        for (int i = 0; i < mHeight; i++) {
            determinant *= mMatrix[i][i];
        }
        
        return determinant;
    }
};

class ERO {
public:
    
    /**
     * Add a row by some multiples of another row
     * @param matrix pointer of matrice to be processed
     * @param target row to be added
     * @param pivot row which multiples will be added to target row
     */
    static void addByAnotherRow (Matrix *matrix, int target, int pivot) {
        double lead;
        lead = matrix->get (pivot, target);

        for (int i = 0; i < matrix->getWidth (); i++) {
            double value;
            value = matrix->get (i, target);
            value = value + ((-lead) * (matrix->get (i, pivot) / matrix->get (pivot, pivot)));
            
            matrix->set (i, target, value);
        }
    }
    
    /**
     * Multiply a row by the inverse of the leading non-zero number of the row
     * @param matrix pointer of matrices to be processed
     * @param row row to be multiplied
     */
    static void divideByConstant (Matrix *matrix, int row) {
        double lead;
        lead = matrix->get (row, row);
        
        for (int i = 0; i < matrix->getWidth (); i++) {
            double value;
            value = matrix->get (i, row);
            value = value / lead;
            
            if (matrix->get (i, row) != 0) {
                matrix->set (i, row, value);
            }
        }
    }
};

class GaussJordan {
public:
    
    /**
     * Convert matrices to its Lower Triangular form
     * @param matrix pointer of matrices to be processed
     * @return Lower Triangular form of the matrices
     */
    static Matrix convertToLowerTriangular (Matrix *matrix) {
        for (int x = 0; x < matrix->getWidth (); x++) {
            for (int y = x+1; y < matrix->getHeight (); y++)
            {
                ERO::addByAnotherRow (matrix, y, x);
            }
        }
        
        return *matrix;
    }
};

/*
 * functions pre-declaration
 */
void getMatrixEntry (Matrix*);
void printMatrix (Matrix);

int main () {
    int size;
    printf ("Masukkan ukuran matriks: ");
    scanf ("%d", &size);
    printf ("\n");
    
    Matrix matrix (size, size);
    getMatrixEntry (&matrix);
    
    printf ("\nMatriks input:\n");
    printMatrix (matrix);
    
    printf ("\nMatriks Segitiga Atas:\n");
    printMatrix (GaussJordan::convertToLowerTriangular (&matrix));
    
    printf ("\nDeterminan: ");
    printf ("%g", matrix.calculateDeterminant ());
    
    getch ();
    return 0;
}

/**
 * Get user input for each matrix entry
 * @param matrix pointer of matrices to be assigned
 */
void getMatrixEntry (Matrix *matrix) {
    for (int y = 0; y < matrix->getHeight (); y++) {
        printf ("Masukkan baris ke-%d: ", y+1);

        for (int x = 0; x < matrix->getWidth (); x++) {
            double input;
            scanf ("%lf", &input);
            matrix->set (x, y, input);
        }
    }
}

/**
 * Print matrices to the screen (console)
 * @param matrix matrices to be printed
 */
void printMatrix (Matrix matrix) {
    for (int y = 0; y < matrix.getHeight (); y++) {
        for (int x = 0; x < matrix.getWidth (); x++) {
            printf (
                "\t%2g%s",
                matrix.get (x, y),
                x == (matrix.getWidth () - 1) ? "\n" : ""
            );
        }
    }
    printf ("\n");
}