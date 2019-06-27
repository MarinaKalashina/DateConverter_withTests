#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_MAIN - don't need to repeat this define in more than one cpp file
#include <boost/test/unit_test.hpp>

#include "Gregorian.h"


BOOST_AUTO_TEST_SUITE(AbsoluteDateCheckSuite)

    BOOST_AUTO_TEST_CASE(ExampleDate)
    {
        GregorianDate gregDate;
        gregDate.SetMonth(12);
        gregDate.SetDay(2);
        gregDate.SetYear(2020);

        BOOST_CHECK_EQUAL(gregDate.getAbsoluteDate(),737761);
    }

    BOOST_AUTO_TEST_CASE(IncorrectDate)
    {
        GregorianDate gregDate;
        gregDate.SetMonth(12);
        gregDate.SetDay(0);
        gregDate.SetYear(2020);

        BOOST_REQUIRE_EQUAL(gregDate.getAbsoluteDate(), 0);
    }
BOOST_AUTO_TEST_SUITE_END()