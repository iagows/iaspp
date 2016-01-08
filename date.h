#ifndef DATE_H
#define DATE_H

#include <sys/time.h>
#include <ctime>
#include "object.h"

//http://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
class IASPP_PUBLIC Date : public Object
{
public:
    enum WeekDay
    {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };

    enum Month
    {
        January,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    Date();//assim pega o horário atual
    Date(int year, Date::Month month, int date=0, int hour=0, int minute=0, int second=0, ulong millisecond=0);
    ~Date();

    int date;//de 1 a 31
    int dateUTC;//de 1 a 31 UTC

    Date::WeekDay day;//0 a 6 (enum)
    Date::WeekDay dayUTC;

    int year;//ano com 4 dígitos
    int yearUTC;

    int hours;//0 a 23
    int hoursUTC;

    int milliseconds;//0 a 999
    int millisecondsUTC;

    int minutes;//0 a 59
    int minutesUTC;

    Date::Month month;//0 a 11 (enum)
    Date::Month monthUTC;

    int seconds;//0 a 59
    int secondsUTC;

    ulong getTime();//segundos desde meia-noite de 1/1/1970 (universal), para esse Date.//epoc
    ulong timeZoneOffset();//diferença entre UTC e o horário local do comp.

    void setFullYear(int year, Date::Month month, int day);
    void setFullHour(int hour, int minute, int second, int millisecond);
    void setMinute(int minute, int second, int millisecond);
    void setMonth(Date::Month month, int day);
    void setSecond(int second, int millisecond);
    void setTime(ulong time);

private:
    ulong getMillisecondsTime();//UTC

    void setCurrentTime();
    void setCurrentTimeUTC();
    ulong _time;
};

#endif // DATE_H
