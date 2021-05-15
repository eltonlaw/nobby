#define BOOST_TEST_MODULE Test GCode Parser
#include <boost/test/included/unit_test.hpp>
#include "gcode_parser.h"

BOOST_AUTO_TEST_CASE(G0)
{
  gcode::Parser parser;
  std::string line("G0 X12");
  gcode::GCodeLine gline = parser.parse(line);
  BOOST_TEST(gline.command.letter == 'G');
  BOOST_TEST(gline.command.number == 0.);
}
