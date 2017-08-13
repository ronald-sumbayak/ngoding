#include <vector>

std::vector<int> prime;
int ways[10001];

void generatePrime () {
    prime.push_back (2);
    
    for (int i = 3; i <= 10000; i++) {
        bool isPrime = true;
        
        for (int p : prime)
            if (i % p == 0) {
                isPrime = false;
                break; }
        
        if (isPrime) {
            prime.push_back (i);
            ways[i] = 2;
        }
    }
}

int get_ways (int n) {
    
}

int main (int argc, char **argv) {
    generatePrime ();
    
}