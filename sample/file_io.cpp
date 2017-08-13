#include <fstream>
#include <iostream>

int main (int args, char const *argv[]) {
    std::string str;
    
    std::ifstream input_stream;
    input_stream.open ("c:/users/ronald/desktop/input.txt");
    input_stream >> str;
    input_stream.close ();
    
    std::cout << "file content: " << str;
    
    std::ofstream output_stream;
    output_stream.open ("c:/users/ronald/desktop/input.txt");
    output_stream << str << std::endl;
    output_stream.close ();
}