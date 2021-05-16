#define BOOST_TEST_MODULE Test GCode Parser
#include <boost/test/included/unit_test.hpp>
#include "gcode_parser.h"

BOOST_AUTO_TEST_CASE(whitespace)
{
  gcode::Parser parser;
  std::string line(" G0");
  gcode::GCodeLine gline = parser.parse(line);
  BOOST_TEST(gline.command.letter == 'G');
  BOOST_TEST(gline.command.number == 0.);
}

BOOST_AUTO_TEST_CASE(numbers)
{
  gcode::Parser parser;
  std::string line("G3");
  gcode::GCodeLine gline = parser.parse(line);
  BOOST_TEST(gline.command.number == 3.);
  line = "G32";
  gline = parser.parse(line);
  BOOST_TEST(gline.command.number == 32.);
}

BOOST_AUTO_TEST_CASE(M0)
{
  gcode::Parser parser;
  std::string line("M0");
  gcode::GCodeLine gline = parser.parse(line);
  BOOST_TEST(gline.command.letter == 'M');
  BOOST_TEST(gline.command.number == 0.);
}
