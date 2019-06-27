#ifndef UNITTESTING_TUTORIAL_JULIAN_H_
#define UNITTESTING_TUTORIAL_JULIAN_H_


#define YEAR_MAX_LENGTH 366
#define JULIAN_EPOCH (-2)
#define MAX_MONTH_LENGTH 31

class JulianDate{
protected:
    int year = 1;
    int month = 1;
    int day = 1;

public:
    JulianDate(){};

    int getDay() {return day;};
    int getMonth() {return month;};
    int getYear() {return year;};

    void CalcJulianDate(int date);

    static int LastMonthDay(int month, int year);
    static int getAbsoluteDate(int m, int d, int y);
};

#endif //UNITTESTING_TUTORIAL_JULIAN_H_