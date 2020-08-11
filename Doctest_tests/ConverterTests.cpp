// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN- don't need to repeat this include in more than one cpp file
#include "doctest.h"

#include "Gregorian.h"
#include "Julian.h"

TEST_CASE("Check various dates") {

    GregorianDate gregDate;
    JulianDate julDate;

    SUBCASE("Gregorian 1/1/1 -> Julian 1/3/1") {
      gregDate.SetMonth(1);
      gregDate.SetDay(1);
      gregDate.SetYear(1);

      int absGregDate = gregDate.getAbsoluteDate();
      julDate.CalcJulianDate(absGregDate);

      CHECK(julDate.getMonth() == 1);
      CHECK(julDate.getDay() == 3);
      CHECK(julDate.getYear() == 1);
    }

    SUBCASE("Gregorian 3/1/100 -> Julian 3/2/100") {
      gregDate.SetMonth(3);
      gregDate.SetDay(1);
      gregDate.SetYear(100);

      int absGregDate = gregDate.getAbsoluteDate();
      julDate.CalcJulianDate(absGregDate);

      CHECK(julDate.getMonth() == 3);
      CHECK(julDate.getDay() == 2);
      CHECK(julDate.getYear() == 100);
    }

    SUBCASE("Gregorian 3/1/300 -> Julian 2/29/300") {
      gregDate.SetMonth(3);
      gregDate.SetDay(1);
      gregDate.SetYear(300);

      int absGregDate = gregDate.getAbsoluteDate();
      julDate.CalcJulianDate(absGregDate);

      CHECK(julDate.getMonth() == 2);
      CHECK(julDate.getDay() == 29);
      CHECK(julDate.getYear() == 300);
    }

    SUBCASE("Gregorian 3/1/900 -> Julian 2/25/900") {
      gregDate.SetMonth(3);
      gregDate.SetDay(1);
      gregDate.SetYear(900);

      int absGregDate = gregDate.getAbsoluteDate();
      julDate.CalcJulianDate(absGregDate);

      CHECK(julDate.getMonth() == 2);
      CHECK(julDate.getDay() == 25);
      CHECK(julDate.getYear() == 900);
    }
  }