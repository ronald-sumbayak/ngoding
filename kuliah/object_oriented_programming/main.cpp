#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int v, **matrix;

void handleDirectedGraph ();
void handleUndirectedGraph ();
void checkGraphType ();
bool isCyclic ();
bool isCyclicUtil (int, bool*, int);

int main () {
    cout << "Vertice: ";
    cin >> v;
    
    matrix = new int*[v+1];
    for (int i = 1; i <= v; i++) {
        matrix[i] = new int[v];
        for (int x = 1; x <= v; x++) matrix[i][x] = 0;
    }
    
    int type;
    cout << endl;
    cout << "Graph type:" << endl;
    cout << "1. Undirected" << endl;
    cout << "2. Directed" << endl;
    cout << "Choice: ";
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
    cout << "Enter adjacency list. Input \"-1 -1\" to stop." << endl;
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
    cout << "Graph type: " << endl;
    checkGraphType ();
}

void checkGraphType () {
    for (int i = 1; i <= v; i++) {
        if (matrix[i][i] == 1) {
            printf ("Graph Complex\n");
            return;
        }
    }
    
    // check cycle
    if (v >= 4 && isCyclic ()) {
        cout << "Cyclic" << endl;
    }
    
    // check wheel
    for (int i = 1; i <= v; i++) {
        int edge = 0;
        for (int j = 1; j <= v; j++) {
            if (matrix[i][j] == 1) edge++; 
        }
        if (edge == v-1) {
            cout << "Wheel" << endl;
            break;
        }
    }
    
    // check complete
    int edge = 0;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (matrix[i][j] == 1) edge++;
        }
    }
    if (edge == ((v*v)-v)) {
        cout << "Complete" << endl;
    }
}

bool isCyclic () {
    bool *visited = new bool[v+1];
    memset (visited, false, sizeof (visited));
    
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

void handleDirectedGraph () {
    cout << "Enter adjacency list. input \"-1 -1\" to stop." << endl;
    int a, b;
    while ((cin >> a >> b) && (a != -1 && b != -1)) {
        matrix[a][b] = 1;
    }
    
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) cout << matrix[i][j] << ends;
        cout << endl;
    }
}