#ifndef UNITTESTING_TUTORIAL_GREGORIAN_H_
#define UNITTESTING_TUTORIAL_GREGORIAN_H_


#define SHORTEST_MONTH 28
#define MAX_MONTH_LENGTH 31

class GregorianDate{
protected:
    int year = 1;
    int month = 1;
    int day = 1;
public:
    GregorianDate() {};

    void SetMonth(int m) {month = m;}
    void SetDay  (int d) {day = d;}
    void SetYear (int y) {year = y;}

    static bool isLeapYear(int year);
    static int LastMonthDay(int month, int year);

    int getAbsoluteDate();
};


#endif //UNITTESTING_TUTORIAL_GREGORIAN_H_