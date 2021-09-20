/*
    names.cpp

    Finds all identifier names in a source-code file.
    Output is one name per line.
*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstring>

int main(int argc, char* argv[]) {

    /* Require filename argument */
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    /* Read filename into string */
    std::ifstream file(argv[1]);
    std::ostringstream buffer;
    buffer << file.rdbuf();
    std::string s = buffer.str();

    /* Output any names */
    std::string::const_iterator pos = s.begin();
    while (pos != s.end()) {

        ++pos;
    }

    return 0;
}
