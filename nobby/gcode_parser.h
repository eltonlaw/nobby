namespace gcode {

// Represents single gcode line fragment containing letter/number
struct GCodeKV {
    char letter;
    float number;
};

// Represents a single action for controller
struct GCodeLine {
    GCodeKV command;
    std::vector<GCodeKV> args;
};

// Parses raw gcode string into GCodeLine object to be used later
class Parser {
public:
    GCodeLine parse(std::string);
private:

};

} // namespace gcode
