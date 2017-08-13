#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node {
    string nama, nrp;
    struct node *left, *right;
    node () { left = right = NULL; }
} Mahasiswa;

Mahasiswa *head = NULL;

void insert (Mahasiswa *root, Mahasiswa *node) {
    if (root->nrp > node->nrp) {
        if (root->left == NULL) root->left = node;
        else insert (root->left, node);
    }
    else if (root->nrp < node->nrp) {
        if (root->right == NULL) root->right = node;
        else insert (root->right, node);
    }
}

Mahasiswa *search (string cari) {
    Mahasiswa *temp = head;
    while (temp != NULL) {
        if (cari == temp->nrp) return temp;
        else if (cari < temp->nrp) temp = temp->left;
        else temp = temp->right;
    }
    return NULL;
}

void display (Mahasiswa *temp) {
    if (temp == NULL) return;
    display (temp->right);
    display (temp->left);
    cout << temp->nrp << endl;
    cout << temp->nama << endl;
    cout << endl;
}

void insert () {
    Mahasiswa *input = new Mahasiswa ();
    cout << "Nama: ";
    cin >> input->nama;
    cout << "NRP:";
    cin >> input->nrp;
    if (head == NULL) head = input;
    else insert (head, input);
}

void search () {
    string nrp;
    cout << "NRP yang mau dicari: ";
    cin >> nrp;
    Mahasiswa *hasil = search (nrp);
    if (hasil == NULL) return;
    else {
        cout << hasil->nrp << endl;
        cout << hasil->nama << endl;
        cout << endl;
    }
}

int main () {
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert Data" << endl;
        cout << "2. Search Data" << endl;
        cout << "3. Display Data (Post Order)" << endl;
        cout << "0. Exit" << endl;
        int pilihan;
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: insert (); break;
            case 2: search (); break;
            case 3: display (head); break;
            case 0: return 0;
            default: break;
        }
    }
}

