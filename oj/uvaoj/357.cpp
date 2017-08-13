#include <cstdio>

int count(int S[], int m, int n )
{
    // If n is 0 then there is 1 solution (do not include any coin)
    if (n == 0)
        return 1;
    
    // If n is less than 0 then no solution exists
    if (n < 0)
        return 0;
    
    // If there are no coins and n is greater than 0, then no solution exist
    if (m <=0 && n >= 1)
        return 0;
    
    // count is sum of solutions (i) including S[m-1] (ii) excluding S[m-1]
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {1, 5, 10, 25, 50};
    int m = sizeof(arr)/sizeof(arr[0]);
    while (true) {
        int x;
        scanf ("%d", &x);
        printf("%d ", count(arr, m, x));
    }
    getchar();
    return 0;
}