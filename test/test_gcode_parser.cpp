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

BOOST_AUTO_TEST_CASE(multiple args)
{
  gcode::Parser parser;
  std::string line("G0 X11 Y13 Z14");
  gcode::GCodeLine gline = parser.parse(line);
  BOOST_TEST(gline.command.letter == 'G');
  BOOST_TEST(gline.command.number == 0.);
  BOOST_TEST(gline.args[0].letter == 'X');
  BOOST_TEST(gline.args[0].number == 11.);
  BOOST_TEST(gline.args[1].letter == 'Y');
  BOOST_TEST(gline.args[1].number == 13.);
  BOOST_TEST(gline.args[2].letter == 'Z');
  BOOST_TEST(gline.args[2].number == 14.);
}
