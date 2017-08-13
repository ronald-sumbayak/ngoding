#include <cstdio>
#include "LinkedList.h"

int main () {
    SinglyLinear<int> linear;
    printf ("%d\n", linear.front ());
    linear.remove_front ();
    linear.insert_front (5);
    linear.insert_back (6);
    linear.insert_at (8, 3);
    printf ("%d\n", linear.front ());
    printf ("%d\n", linear.back ());
    printf ("%d\n", linear.at (1));
    linear.reverse ();
    printf ("%d\n", linear.front ());
    printf ("%d\n", linear.back ());
    printf ("%d\n", linear.at (1));
    linear.remove_at (1);
    linear.remove_back ();
    linear.remove_front ();
    linear.clear ();
}