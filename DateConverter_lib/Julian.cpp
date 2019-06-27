#include "Julian.h"

void JulianDate::CalcJulianDate(int date) {

   if (!date) {
        year = month = day = 0;
   }
   else {
        year = ((date+JULIAN_EPOCH)/YEAR_MAX_LENGTH);
        while (date>=getAbsoluteDate(1, 1, year+1))
            year++;
        while (date>getAbsoluteDate(month, LastMonthDay(month, year), year))
            month++;
        int JulDay = getAbsoluteDate(month, 1, year);
        day = date-JulDay+1;
   }
}

int JulianDate::getAbsoluteDate(int m, int d, int y) {
    int N = d;                         // days this month
    for (int mm = m - 1;  mm > 0; mm--) // days in prior months this year
        N = N + LastMonthDay(mm, y);
    return
            (N                     // days this year
                    + 365 * (y - 1)    // days in previous years ignoring leap days
                    + (y - 1)/4        // leap days before this year...
                    + JULIAN_EPOCH);       // days elapsed before absolute date 1
}

int JulianDate::LastMonthDay(int m, int y)
{
    switch (m) {
    case 2:
        if ((y % 4) == 0)
            return 29;
        else
            return 28;
    case 4:
    case 6:
    case 9:
    case 11: return 30;
    default:
        return MAX_MONTH_LENGTH;
    }
}