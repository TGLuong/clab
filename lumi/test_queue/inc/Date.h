#include <string>


#ifndef DATE_H
#define DATE_H

class Date {
private:
    int m_year;
    int m_month;
    int m_day;
    std::string s;

public:
    Date(int year, int month, int day, std::string s): m_year(year), m_month(month), m_day(day), s(s) {  }
    
    std::string getString() { return s; } 
    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay()  { return m_day; }
};

#endif
