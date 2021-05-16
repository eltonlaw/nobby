#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "gcode_parser.h"

namespace gcode {

GCodeLN read_next_ln(std::stringstream& ss) {
    char c; 
    GCodeLN ret;

    // Skip all whitespace. First none whitespace value should be
    // letter
    while (isspace(c = ss.get()));
    // FIXME: add error handling if not letter
    ret.letter = c;

    std::string number_string;
    while (isdigit(c = ss.get())) {
        number_string.push_back(c);
    }
    ss.unget();
    ret.number = std::stof(number_string);

    return ret;
}

GCodeLine Parser::parse(std::string line) {
    std::stringstream ss;
    // FIXME: make sure that line is capitalized
    ss << line;
    std::vector<GCodeLN> lns;

    GCodeLN ln = read_next_ln(ss);
    lns.push_back(ln);

    GCodeLine gline {
         .command = lns[0],
         .args = std::vector<GCodeLN>(lns.begin() + 1, lns.end()),
    };
    return gline;
}

} // namespace gcode
