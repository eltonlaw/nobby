#define BOOST_TEST_MODULE Test GCode Parser
#include <boost/test/included/unit_test.hpp>
#include "gcode_parser.h"

BOOST_AUTO_TEST_CASE(first_test)
{
  int i = 1;
  GCodeParser parser;
  BOOST_TEST(i);
  BOOST_TEST(i == 1);
  BOOST_TEST(parser.x == 5);
}
