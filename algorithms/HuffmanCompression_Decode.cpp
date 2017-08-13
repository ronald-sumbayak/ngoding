#include <fstream>
#include <map>
#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;

int main (int argc, char **argv) {
    cout << "Huffman Compression - Decode (:" << endl;
    
    // variables declaration.
    ifstream input;
    int dictSize;
    char c;
    string original;
    stringstream ss;
    map<string, int> huffmanCodeReverse;
    string byte, content, temp, decoded;
    
    input.open ("output.roni");
    
    // get dictionary size.
    input >> dictSize;
    ss << dictSize;
    original = ss.str () + " ";
    
    // get dictionary
    for (int i = 0; i < dictSize; i++) {
        string code;
        char ch;
        input.get (ch); // retrieve '\n' in input file
        input.get (ch);
        input >> code;
        
        original += ch;
        original += code;
        huffmanCodeReverse[code] = ch;
    }
    
    input.get (c);
    
    cout << endl << endl << endl;
    cout << "Dictionary: " << endl << endl;
    
    // print dictionary
    for (map<string, int>::iterator i = huffmanCodeReverse.begin (); i != huffmanCodeReverse.end (); i++)
        cout << i->first << " = " << (char) i->second << endl;
    
    // get remaining input (encoded content)
    while (input.get (c)) {
        original.push_back (c);
        content.push_back (c);
    }
    
    cout << endl << endl << endl;
    cout << "Encoded content" << endl << endl;
    cout << content << endl;
    
    for (int i = 0; i < content.length ()-1; i++)
        byte.append (bitset<8> ((unsigned long long int) content[i]).to_string ());
    
    int leading = true;
    temp = bitset<8> ((unsigned long long int) content[content.length ()-1]).to_string ();
    for (int i = 0; i < temp.length (); i++) {
        if (temp[i] == '0' && leading) continue;
        leading = false;
        byte.push_back (temp[i]);
    }
    
    temp = "";
    cout << byte << endl;
    for (int i = 0; i <= byte.length (); i++) {
        temp += byte[i];
        cout << temp << endl;
        if (huffmanCodeReverse.count (temp)) {
            decoded += huffmanCodeReverse[temp];
            temp = "";
        }
    }
    
    cout << endl << endl << endl;
    cout << "Decoded content:" << endl << endl;
    cout << decoded;
}