#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int v, **matrix;

void handleDirectedGraph ();
void handleUndirectedGraph ();
void checkGraphType ();
bool isCyclic ();
bool isCyclicUtil (int, bool*, int);
bool isWheel ();

int main () {
    cout << "Masukkan berapa vertex : ";
    cin >> v;
    
    matrix = new int*[v+1];
    for (int i = 1; i <= v; i++) {
        matrix[i] = new int[v+1];
        for (int x = 1; x <= v; x++) matrix[i][x] = 0;
    }
    
    int type;
    cout << endl;
    cout << "Tipe Graf:" << endl;
    cout << "1. Tidak Berarah" << endl;
    cout << "2. Berarah" << endl;
    cout << "Pilihan : ";
    cin >> type;
    
    switch (type) {
        case 1: handleUndirectedGraph (); break;
        case 2: handleDirectedGraph (); break;
        default: break;
    }
    
    system ("pause");
    return 0;
}

void handleUndirectedGraph () {
    cout << endl;
    cout << "Masukkan adjacency. input \"-1 -1\" untuk berhenti." << endl;
    int a, b;
    
    while ((cin >> a >> b) && (a != -1 && b != -1)) {
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }
    
    cout << endl << endl;
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) cout << matrix[i][j] << ends;
        cout << endl;
    }
    
    cout << endl;
    cout << "Tipe Graf : " << endl;
    checkGraphType ();
}

void checkGraphType () {
    
    for (int i = 1; i <= v; i++) {
        if (matrix[i][i] == 1) {
            cout << "Graf tidak sederhana" <<endl;
            return;
        }
    }
    
    cout << "Simple Graph:" << endl;
    
    // check cycle
    if (v >= 3 && isCyclic ()) cout << "Cycle" << endl;
    // check wheel
    if (v > 3 && isWheel ()) cout << "Wheel" << endl;
    
    // check complete
    int edge = 0;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (matrix[i][j] == 1) edge++;
        }
    }
    if (edge == (v*v) - v) {
        cout << "Complete" << endl;
    }
}

bool isCyclic () {
    bool *visited = new bool[v+1];
    memset (visited, false, sizeof (visited)+1);
    
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            if (isCyclicUtil (i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclicUtil (int i, bool *visited, int parent) {
    visited[i] = true;
    for (int j = 1; j <= v; j++) {
        if (matrix[i][j] == 1) {
            if (!visited[j]) {
                if (isCyclicUtil (j, visited, i))
                    return true;
            }
            else if (j != parent)
                return true;
        }
    }
    return false;
}

bool isWheel () {
    for (int i = 1; i <= v; i++) {
        int adj = 0;
        for (int j = 1; j <= v; j++) {
            if (matrix[i][j] == 1) adj++;
        }
        
        if (adj == v-1) {
            int visit[v+1];
            memset (visit, 0, sizeof (visit)+1);
            for (int x = 1; x <= v; x++) {
                if (x == i) continue;
                
                std::vector<int> chain;
                int edge = 0;
                for (int e = 1; e <= v; e++) {
                    if (e == i) continue;
                    if (matrix[x][e] == 1) {
                        edge += matrix[x][e];
                        chain.push_back (e);
                    }
                }
                
                if (edge != 2) break;
                visit[chain[0]]++;
                visit[chain[1]]++;
            }
            
            bool wheel = true;
            for (int x = 1; x <= v; x++) {
                if (x == i) continue;
                if (visit[x] != 2) {
                    wheel = false;
                    break;
                }
            }
            
            if (wheel) return true;
        }
    }
    
    return false;
}

void handleDirectedGraph () {
    cout << "Masukkan adjacency. input \"-1 -1\" untuk berhenti." << endl;
    int a, b;
    while ((cin >> a >> b) && (a != -1 && b != -1)) {
        matrix[a][b] = 1;
    }
    
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) cout << matrix[i][j] << ends;
        cout << endl;
    }
}