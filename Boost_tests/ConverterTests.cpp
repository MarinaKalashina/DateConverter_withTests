#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "Gregorian.h"
#include "Julian.h"

struct DateConverterFixture {

    DateConverterFixture()  {
        gregDate = new GregorianDate();
        julDate = new JulianDate();
    }

    ~DateConverterFixture() {
        delete gregDate;
        delete julDate;
    }

    GregorianDate * gregDate;
    JulianDate * julDate;

};

BOOST_FIXTURE_TEST_CASE( FirstDayEver, DateConverterFixture ) // 1/1/1 -> 1/3/1
{
    gregDate->SetMonth(1);
    gregDate->SetDay(1);
    gregDate->SetYear(1);

    int absGregDate = gregDate->getAbsoluteDate();
    julDate->CalcJulianDate(absGregDate);

    BOOST_CHECK_EQUAL(julDate->getMonth(),1);
    BOOST_CHECK_EQUAL(julDate->getDay(),3);
    BOOST_CHECK_EQUAL(julDate->getYear(),1);
}

BOOST_FIXTURE_TEST_CASE( PlusOneDiff, DateConverterFixture ) // 3/1/100 -> 3/2/100
{
    gregDate->SetMonth(3);
    gregDate->SetDay(1);
    gregDate->SetYear(100);

    int absGregDate = gregDate->getAbsoluteDate();
    julDate->CalcJulianDate(absGregDate);

    BOOST_CHECK_EQUAL(julDate->getMonth(),3);
    BOOST_CHECK_EQUAL(julDate->getDay(),2);
    BOOST_CHECK_EQUAL(julDate->getYear(),100);
}

BOOST_FIXTURE_TEST_CASE( MinusOne_Leap, DateConverterFixture ) // 3/1/300 -> 2/29/300
{
    gregDate->SetMonth(3);
    gregDate->SetDay(1);
    gregDate->SetYear(300);

    int absGregDate = gregDate->getAbsoluteDate();
    julDate->CalcJulianDate(absGregDate);

    BOOST_CHECK_EQUAL(julDate->getMonth(),2);
    BOOST_CHECK_EQUAL(julDate->getDay(),29);
    BOOST_CHECK_EQUAL(julDate->getYear(),300);
}

BOOST_FIXTURE_TEST_CASE( PlusFour_Leap, DateConverterFixture ) // 3/1/900 -> 2/25/900
{
    gregDate->SetMonth(3);
    gregDate->SetDay(1);
    gregDate->SetYear(900);

    int absGregDate = gregDate->getAbsoluteDate();
    julDate->CalcJulianDate(absGregDate);

    BOOST_CHECK_EQUAL(julDate->getMonth(),2);
    BOOST_CHECK_EQUAL(julDate->getDay(),25);
    BOOST_CHECK_EQUAL(julDate->getYear(),900);
}