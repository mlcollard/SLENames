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

std::string::const_iterator matchName(std::string::const_iterator pos,
                                      std::string::const_iterator end) {

    auto curpos = pos;

    /* [a-zA-Z] */
    if (!(curpos != end && isalpha(*curpos)))
        return pos;
    ++curpos;

    /* [a-zA-Z0-9]* */
    while (curpos != end && isalnum(*curpos))
        ++curpos;

    return curpos;
}

std::string::const_iterator matchBlockComment(std::string::const_iterator pos,
                                      std::string::const_iterator end) {

    auto curpos = pos;

    /* [/] */
    if (!(curpos != end && *curpos == '/'))
        return pos;
    ++curpos;

    /* [*] */
    if (!(curpos != end && *curpos == '*'))
        return pos;
    ++curpos;

    /* .*?[*][/] */
    while (curpos != end) {

        /* match the sequence [*][/] */
        if (curpos != end && *curpos == '*') {
            ++curpos;
            if (curpos != end && *curpos == '/') {
                ++curpos;
                return curpos;
            }
        }

        /* [^*]* */
        while (curpos != end && *curpos != '*')
            ++curpos;
    }

    return pos;
}

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

        auto startpos = pos;
        switch (*startpos) {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            pos = matchName(startpos, s.end());
            if (pos != startpos) {
                std::cout << std::string(startpos, pos) << '\n';
            } else {
                ++pos;
            }
            break;
        case '/':
            pos = matchBlockComment(startpos, s.end());
            if (pos == startpos)
                ++pos;
            break;
        default:
            ++pos;
        }
    }

    return 0;
}
