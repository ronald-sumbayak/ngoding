#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <queue>
#include <bitset>
#include <cstdlib>

using namespace std;

struct Node {
    char character;
    int  frequency;
    struct Node *left, *right;
    
    Node (char character, int frequency, struct Node *left = 0, struct Node *right = 0) {
        this->character = character;
        this->frequency = frequency;
        this->right = right;
        this->left = left;
    }
};

struct Compare {
    bool operator () (const Node *a, const Node *b) {
        return a->frequency > b->frequency;
    }
};

map<char, string> huffmanCode;

/**
 * utility to determine Huffman Code for each characters
 * (which is the leaf). Append "0" to code every time it
 * traverse to left child, and "1" to right child.
 * 
 * @param node current node being traversed. 
 * @param code current code builded.
 */
void build (Node *node, string code) {
    if (!node) return;
    if (node->character) huffmanCode[node->character] = code;
    build (node->left, code + "0");
    build (node->right, code + "1");
}

void write (string encoded) {
    ofstream output;
    stringstream ss; // temporarily stores size of huffman code.
    string bit; // stores result of string in bytes.
    
    /**
     * write huffman code data (number of characters and huffman
     * code for every characters) to the beginning of the file
     * to be able to decode the files back.
     */
    
    ss << huffmanCode.size ();
    bit = ss.str () + "\n";
    
    for (map<char, string>::iterator i = huffmanCode.begin (); i != huffmanCode.end (); i++) {
        bitset<8> bs (i->second);
        bit += i->first;
        bit += i->second;
        bit += "\n";
    }
    
    /**
     * get every 8 bit (1 byte) string in encoded string and
     * convert it into binary number then put it into output
     * file.
     */
    for (int i = 0; i < encoded.length (); i += 8) {
        bitset<8> bs (encoded.substr ((unsigned int) i, 8));
        bit += (char) bs.to_ulong ();
    }
    
    cout << endl << endl << endl;
    cout << "Encoded content:" << endl << endl;
    cout << bit << "<EOS>" << endl;
    
    output.open ("output.roni");
    output << bit;
    output.close ();
}

int main (int argc, char **argv) {
    cout << "Huffman Compression - Encode :)" << endl;
    
    // variables declaration.
    ifstream input;
    string original; // stores the original content string of input file.
    char c;
    map<char, int> count; // stores number of characters occurrences.
    priority_queue<Node*, vector<Node*>, Compare> q; // min heap.
    string encoded; // stores encoded string in bit string.
    
    input.open ("input.txt");
    
    /*
     * read every characters in file input (stream) one by one
     * and increment its value for each occurrences. value stores
     * in a map.
     */
    while (input.get (c)) {
        original.push_back (c);
        count[c]++;
    }
    
    input.close ();
    
    cout << endl << endl << endl;
    cout << "Original content:" << endl << endl;
    cout << original << "<EOF>" << endl;
    
    cout << endl << endl << endl;
    cout << "Character List:" << endl << endl;
    
    /**
     * iterate through all elements in map which stores
     * the number of characters occurrences, build a node
     * from it and insert into a heap (priority queue).
     */
    for (map<char, int>::iterator i = count.begin (); i != count.end (); i++) {
        q.push (new Node (i->first, i->second));
        cout << i->first << " = " << i->second << endl;
    }

    /**
     * extract top two value (two nodes with lowest frequency).
     * Create a new internal node with frequency equal to the
     * sum of the two nodes frequencies. Make the first extracted
     * node as its left child and the other extracted node as
     * its right child. Add this node to the heap.
     */
    while (q.size () > 1) {
        Node *f = q.top (); q.pop ();
        Node *s = q.top (); q.pop ();
        q.push (new Node (0, f->frequency + s->frequency, f, s));
    }
    
    /**
     * build Huffman Code by traverse all the nodes all the way
     * from root to leaf. Initial code start from empty string ("").
     */
    build (q.top (), "");

    cout << endl << endl << endl;
    cout << "Huffman Code:" << endl << endl;
    
    /**
     * iterate through all elements in map which stores
     * Huffman Code for every characters and print pair
     * of characters and its value.
     */
    for (map<char, string>::iterator i = huffmanCode.begin (); i != huffmanCode.end (); i++)
        cout << i->first << " = " << i->second << endl;
    
    /**
     * encode string of original content with the
     * corresponding Huffman Code for each character.
     */
    for (int i = 0; i < original.length (); i++)
        encoded += huffmanCode[original[i]];

    cout << endl << endl << endl;
    cout << "Encoded string in bit string:" << endl << endl;
    cout << encoded << "<EOS>" << endl;

    write (encoded);

    cout << endl << endl << endl;
    cout << "Encoded :)" << endl << endl;
    system ("pause");
}