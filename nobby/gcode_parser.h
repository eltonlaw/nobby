#include <sstream>
#include <vector>

namespace gcode {

// Represents single gcode line fragment containing letter/number
struct GCodeLN {
    char letter;
    float number = -1.;
};

// Represents a single action for controller
struct GCodeLine {
    GCodeLN command;
    std::vector<GCodeLN> args;
};

GCodeLN read_next_ln(std::stringstream& ss);

// Parses raw gcode string into GCodeLine object to be used later
class Parser {
public:
    GCodeLine parse(std::string);
private:

};

} // namespace gcode
