#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "gcode_parser.h"

namespace gcode {

GCodeKV read_next_kv() {
    return {
        .letter = 'G',
        .number = 0.
    };
}

GCodeLine Parser::parse(std::string line) {
    std::stringstream ss;
    ss << line;
    std::vector<GCodeKV> kvs;
    kvs.push_back(read_next_kv());
    GCodeLine gline {
         .command = kvs[0],
    };
    return gline;
}

} // namespace gcode
