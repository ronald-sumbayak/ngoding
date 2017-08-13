#include <cstdio>

void printArray (int *boxes, int nBox) {
    for (int x = 0; x < nBox; x++) {
        printf ("%d ", boxes[x]);
    }
    printf ("\n");
}
w
long double permutate (int *boxes, int k, int nBox) {
    long double result = 1;
    long double repeat;
    int x = 0;
    
    repeat = 1;
    while (x < k) {
        if (boxes[x] == boxes[x-1]) repeat++;
        else repeat = 1;
        
        result *= (x+1);
        result /= repeat;
        x++;
    }
    
    repeat = 1;
    while (x < nBox) {
        result *= (x+1);
        result /= repeat;
        
        repeat++;
        x++;
    }
    
    return result;
}

long double generateCombination (int *boxes, int nBox) {
    long double result = 0;
    int k = 1;
    
    while (true) {
        if (k < nBox) {
            //printArray (boxes, k+1);
            //printf ("(%Lf)\n", permutate (boxes, nBox, k+1));
            result += permutate (boxes, nBox, k+1);
        }
        
        int pivot = 0;
        while (k >= 0 && boxes[k] == 1) {
            pivot += boxes[k];
            k--;
        }
        
        if (k < 0) break;
        
        boxes[k]--;
        pivot++;
        
        while (pivot > boxes[k]) {
            boxes[k+1] = boxes[k];
            pivot = pivot - boxes[k];
            k++;
        }
        
        boxes[k+1] = pivot;
        k++;
    }
    
    return result;
}

int main () {
    int nCandy, nBox;
    scanf ("%d %d", &nCandy, &nBox);
    
    int *boxes;
    boxes = new int [nBox] {(nCandy / 2), (nCandy / 2)};
    
    long double partitions;
    partitions = generateCombination (boxes, nBox);
    printf ("%Lf\n", partitions);
    
    return 0;
}