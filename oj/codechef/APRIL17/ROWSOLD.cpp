#include <iostream>
using namespace std;

int main (int argc, char **argv) {
    string row;
    int tc;
    cin >> tc;
    
    while (tc--) {
        cin >> row;
        long long streak=0, span=0, time=0;
        char last = row[0];
        
        for (int i = 0; i < row.length (); i++) {
            if (row[i] == '1') {
                if (row[i] != last) {
                    time += (streak * (span+1));
                    span = 0;
                }
                streak++;
            }
            else span++;
            last = row[i];
        }
        
        if (last == '0') time += (streak * (span+1));
        cout << time << endl;
    }
}