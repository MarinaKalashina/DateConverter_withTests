#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Gregorian.h"

TEST_CASE("ExampleDate"){  // 12/2/2020 -> 737761
  GregorianDate gregDate;
  gregDate.SetMonth(12);
  gregDate.SetDay(2);
  gregDate.SetYear(2020);
  CHECK(gregDate.getAbsoluteDate() == 737761);
}

TEST_CASE("IncorrectDate"){  // 12/0/2020 -> 0
  GregorianDate gregDate;
  gregDate.SetMonth(12);
  gregDate.SetDay(0);
  gregDate.SetYear(2020);
  REQUIRE(gregDate.getAbsoluteDate() == 0);
}

