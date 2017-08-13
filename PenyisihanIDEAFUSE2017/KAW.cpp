#include <iostream>
#include <map>
using namespace std;

int main (int argc, char **argv) {
    map<string, char> m;
    
    m.insert (make_pair ("0000000", ' '));
    
    m.insert (make_pair ("0000101", 'a'));
    m.insert (make_pair ("1110100", 'b'));
    m.insert (make_pair ("0001100", 'c'));
    m.insert (make_pair ("1010000", 'd'));
    m.insert (make_pair ("0011001", 'e'));
    m.insert (make_pair ("1100100", 'f'));
    m.insert (make_pair ("1010010", 'g'));
    m.insert (make_pair ("1100101", 'h'));
    m.insert (make_pair ("0011011", 'i'));
    m.insert (make_pair ("1110011", 'j'));
    m.insert (make_pair ("0100010", 'k'));
    m.insert (make_pair ("1101000", 'l'));
    m.insert (make_pair ("0010100", 'm'));
    m.insert (make_pair ("1000011", 'n'));
    m.insert (make_pair ("0110000", 'o'));
    m.insert (make_pair ("0111001", 'p'));
    m.insert (make_pair ("1111100", 'q'));
    m.insert (make_pair ("0010011", 'r'));
    m.insert (make_pair ("1100001", 's'));
    m.insert (make_pair ("0101001", 't'));
    m.insert (make_pair ("0000110", 'u'));
    m.insert (make_pair ("0010110", 'v'));
    m.insert (make_pair ("0111010", 'w'));
    m.insert (make_pair ("0001101", 'x'));
    m.insert (make_pair ("1001111", 'y'));
    m.insert (make_pair ("1101011", 'z'));
    
    m.insert (make_pair ("1000101", 'A'));
    m.insert (make_pair ("0110100", 'B'));
    m.insert (make_pair ("1001100", 'C'));
    m.insert (make_pair ("0010000", 'D'));
    m.insert (make_pair ("1011001", 'E'));
    m.insert (make_pair ("0100100", 'F'));
    m.insert (make_pair ("0010010", 'G'));
    m.insert (make_pair ("0100101", 'H'));
    m.insert (make_pair ("1011011", 'I'));
    m.insert (make_pair ("0110011", 'J'));
    m.insert (make_pair ("1100010", 'K'));
    m.insert (make_pair ("0101000", 'L'));
    m.insert (make_pair ("1010100", 'M'));
    m.insert (make_pair ("0000011", 'N'));
    m.insert (make_pair ("1110000", 'O'));
    m.insert (make_pair ("1111001", 'P'));
    m.insert (make_pair ("0111100", 'Q'));
    m.insert (make_pair ("1010011", 'R'));
    m.insert (make_pair ("0100001", 'S'));
    m.insert (make_pair ("1101001", 'T'));
    m.insert (make_pair ("1000110", 'U'));
    m.insert (make_pair ("1010110", 'V'));
    m.insert (make_pair ("1111010", 'W'));
    m.insert (make_pair ("1001101", 'X'));
    m.insert (make_pair ("0001111", 'Y'));
    m.insert (make_pair ("0101011", 'Z'));
    
    string input;
    while (getline (cin, input)) {
        for (int i = 0; i < input.length (); i+=7)
            cout << m[input.substr (i, 7)];
        cout << endl;
    }
    
    return 0;
}
