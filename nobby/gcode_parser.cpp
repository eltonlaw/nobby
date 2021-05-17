#include <iostream>
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
    // FIXME: make sure that there's no whitespace at the end
    ss << line;
    std::vector<GCodeLN> lns;

    GCodeLN ln;
    while (true) {
        ln = gcode::read_next_ln(ss);
        lns.push_back(ln);
        if (ss.rdbuf()->in_avail() == 0)
            break;
    }

    GCodeLine gline {
         .command = lns[0],
         .args = std::vector<GCodeLN>(lns.begin() + 1, lns.end()),
    };
    return gline;
}

} // namespace gcode
