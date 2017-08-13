#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main (int argc, char** argv) {
    int tc;
    scanf ("%d", &tc);
    
    while (tc--) {
        string a, b;
        cin >> a >> b;
        int dist[a.length ()+1][b.length ()+1]={};
        for (int i = 0; i < a.length (); i++) dist[0][i] = i;
        for (int i = 0; i < b.length (); i++) dist[i][0] = i;
        for (int i = 1; i <= a.length (); i++)
            for (int j = 1; j <= b.length (); j++)
                if (a[i-1] == b[j-1])
                    dist[i][j] = dist[i-1][j-1];
                else
                    dist[i][j] = 1 + min (min (dist[i-1][j], dist[i][j-1]), dist[i-1][j-1]);
        
        cout << dist[a.length ()][b.length ()] << endl; 
    }
}