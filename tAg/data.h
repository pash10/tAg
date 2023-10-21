#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:

    // Default constructor
    Date() : year(1), month(1), day(1) {}

    // Parameterized constructor
    Date(int d, int m, int y) {
        setDay(d);
        setMonth(m);
        setYear(y);
    }

    // Copy constructor
    Date(const Date& date) {
        setDay(date.getDay());
        setMonth(date.getMonth());
        setYear(date.getYear());
    }

    bool operator<(const Date& other) const {
        if (this->year != other.year) {
            return this->year < other.year;
        }
        if (this->month != other.month) {
            return this->month < other.month;
        }
        return this->day < other.day;
    }

    bool operator>(const Date& other) const {
        if (this->year != other.year) {
            return this->year > other.year;
        }
        if (this->month != other.month) {
            return this->month > other.month;
        }
        return this->day > other.day;
    }

    bool operator==(const Date& other) const {
        return this->year == other.year && this->month == other.month && this->day == other.day;
    }

    // Getter functions
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setter functions
    void setYear(int year) {
        this->year = (year > 0) ? year : 1;
    }

    void setMonth(int month) {
        if (month > 12) {
            this->month = 12;
        }
        else if (month < 1) {
            this->month = 1;
        }
        else {
            this->month = month;
        }
    }

    // Note: This day setter is simplistic and doesn't account for different days in each month or leap years
    void setDay(int day) {
        if (day > 31) {
            this->day = 31;
        }
        else if (day < 1) {
            this->day = 1;
        }
        else {
            this->day = day;
        }
    }

    void printDate() const {
        std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
    }
};

#endif
