
#include "Gregorian.h"

int GregorianDate::getAbsoluteDate () {

    if ((year < 1) || (day < 1) || (day > MAX_MONTH_LENGTH) || (month < 1) || (month > 12)) return 0;

    int N = day;           // days this month
    for (int m = month - 1; m > 0; m--)
        N = N + LastMonthDay(m, year);
    return
            (N                    // days this year
                    + 365 * (year - 1)   // days in previous years ignoring leap days
                    + (year - 1) / 4       // JulianCalendar leap days before this year...
                    - (year - 1) / 100     // ...minus prior century years...
                    + (year - 1) / 400);   // ...plus prior years divisible by 400
}

int GregorianDate::LastMonthDay(int month, int year)
{
    switch (month) {
    case 2:
        return (isLeapYear(year) ? 29 : SHORTEST_MONTH);
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

bool GregorianDate::isLeapYear(int year) {

    bool result = (((year % 4) == 0) && ((year % 100) != 0))
            || ((year % 400) == 0);

    return result;
}
