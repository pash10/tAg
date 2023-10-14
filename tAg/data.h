#ifndef DATA_H
#define DATA_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
   
    // Parameterized constructor that validates input

    Date() {
        this->year = 1;
        this->month = 1;
        this->day = 1;
    }

    Date(int d, int m, int y) {
        setDay(d);
        setMonth(m);
        setYear(y);
    }

    Date(Date& date) {
        setDay(date.getDay());
        setMonth(date.getMonth());
        setYear(date.getYear());
    }


    

    // Getter functions
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setter functions
    void setYear (int year) {
        if (year <= 0) {
            this->year = 0;
        }
        else {
            this->year = year;
        }
    }
    void setMonth(int month) {
        if (month >= 12) {
            this->month = 12;
        }
        else if (month <= 0) {
            this->month = 0;
        }
        else {
            this->month = month;
        }
    }
    void setDay(int day) {
        if (day >= 30) {
            this->day = 30;
        }
        else if (day <= 0) {
            this->day = 0;
        }
        else {
            this->day = day;
        }
    }

    void PrinDat() const {
        std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
    }
};
#endif