#include "gtest/gtest.h"
#include "Julian.h"
#include "Gregorian.h"


class DateConverterFixture : public ::testing::Test {

protected:
    virtual void SetUp()
    {
        gregDate = new GregorianDate();
        julDate = new JulianDate();
    }

    virtual void TearDown() {
        delete gregDate;
        delete julDate;
    }

    GregorianDate * gregDate;
    JulianDate * julDate;
};

TEST_F(DateConverterFixture, FirstDayEver){ // 1/1/1 -> 1/3/1

    gregDate->SetMonth(1);
    gregDate->SetDay(1);
    gregDate->SetYear(1);

    int absGregDate = gregDate->getAbsoluteDate();
    julDate->CalcJulianDate(absGregDate);

    EXPECT_EQ(julDate->getMonth(),1);
    EXPECT_EQ(julDate->getDay(),3);
    EXPECT_EQ(julDate->getYear(),1);

}

TEST_F(DateConverterFixture, PlusOneDiff){ // 3/1/100 -> 3/2/100

    gregDate->SetMonth(3);
    gregDate->SetDay(1);
    gregDate->SetYear(100);

    int absGregDate = gregDate->getAbsoluteDate();
    julDate->CalcJulianDate(absGregDate);

    EXPECT_EQ(julDate->getMonth(),3);
    EXPECT_EQ(julDate->getDay(),2);
    EXPECT_EQ(julDate->getYear(),100);
}

TEST_F(DateConverterFixture, MinusOne_Leap){ // 3/1/300 -> 2/29/300

    gregDate->SetMonth(3);
    gregDate->SetDay(1);
    gregDate->SetYear(300);

    int absGregDate = gregDate->getAbsoluteDate();
    julDate->CalcJulianDate(absGregDate);

    EXPECT_EQ(julDate->getMonth(),2);
    EXPECT_EQ(julDate->getDay(),29);
    EXPECT_EQ(julDate->getYear(),300);
}


TEST_F(DateConverterFixture, PlusFour_Leap){ // 3/1/900 -> 2/25/900

    gregDate->SetMonth(3);
    gregDate->SetDay(1);
    gregDate->SetYear(900);

    int absGregDate = gregDate->getAbsoluteDate();
    julDate->CalcJulianDate(absGregDate);

    EXPECT_EQ(julDate->getMonth(),2);
    EXPECT_EQ(julDate->getDay(),25);
    EXPECT_EQ(julDate->getYear(),900);
}
