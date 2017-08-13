#include <cstdio>
#include <queue>
#include <algorithm>

int main (int argc, char **argv) {
    int x, median;
    std::vector<int> list;
    
    while (scanf ("%d", &x) != EOF) {
        list.push_back (x);
        std::sort (list.begin (), list.end ());
        median = list[list.size ()/2];
        if (list.size () % 2 == 0) median = (median + list[(list.size ()/2)-1]) / 2;
        printf ("%d\n", median);
    }
}

