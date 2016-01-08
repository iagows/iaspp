#include "date.h"

Date::Date():Object()
{
    this->_time = getMillisecondsTime();

    this->setCurrentTime();

    this->setCurrentTimeUTC();
}

Date::Date(int year, Date::Month month, int date, int hour, int minute, int second, ulong millisecond)
{
    this->year = year;
    this->month = month;
    this->date = date;
    this->hours = hour;
    this->minutes = minute;
    this->seconds = second;
    this->milliseconds = millisecond;

    //TODO ver o dia da semana
}

Date::~Date()
{

}

ulong Date::getTime()
{
    return this->_time;
}

void Date::setFullYear(int year, Date::Month month, int day)
{
    this->year = year;
    this->setMonth(month, day);
}

void Date::setFullHour(int hour, int minute, int second, int millisecond)
{
    this->hours = hour;
    this->setMinute(minute, second, millisecond);
}

void Date::setMinute(int minute, int second, int millisecond)
{
    this->minutes = minute;
    this->setSecond(second, millisecond);
}

void Date::setMonth(Date::Month month, int day)
{
    this->month = month;
    this->date = day;
}

void Date::setSecond(int second, int millisecond)
{
    this->seconds = second;
    this->milliseconds = millisecond;

    return;
}

void Date::setTime(ulong time)
{
    this->_time = time;
}

ulong Date::getMillisecondsTime()
{
    struct timeval tv;
    if(gettimeofday(&tv, NULL) != 0) return 0;
    return (ulong)((tv.tv_sec * 1000ul) + (tv.tv_usec / 1000ul));
}

void Date::setCurrentTime()
{
    time_t now = time(0);
    time(&now);
    tm  *localTime = localtime(&now);
    this->year = localTime->tm_year + 1900;
    this->month = (Date::Month)localTime->tm_mon;
    this->date = localTime->tm_mday;
    this->hours = localTime->tm_hour;
    this->minutes = localTime->tm_min;
    this->seconds = localTime->tm_sec;
    this->day = (Date::WeekDay)localTime->tm_wday;

    delete localTime;
}

void Date::setCurrentTimeUTC()
{
    time_t now = time(0);
    time(&now);
    tm *utcTime = gmtime(&now);
    this->yearUTC = utcTime->tm_year + 1900;
    this->monthUTC = (Date::Month)utcTime->tm_mon;
    this->dateUTC = utcTime->tm_mday;
    this->hoursUTC = utcTime->tm_hour;
    this->minutesUTC = utcTime->tm_min;
    this->secondsUTC = utcTime->tm_sec;
    this->dayUTC = (Date::WeekDay)utcTime->tm_wday;

    delete utcTime;
}
