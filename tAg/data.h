#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor initializing with default values
    Date() : day(1), month(1), year(2000) {}

    // Parameterized constructor that validates input
    Date(int d, int m, int y) {
        setDay(d);
        setMonth(m);
        setYear(y);
    }

    // Destructor
    ~Date() {
        std::cout << "Date object destroyed." << std::endl;
    }

    // Getter functions
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Setter functions
    void setDay(int d) {
        if (d > 0 && d <= 30) {
            day = d;
        }
        else {
            day = 0;
        }
    }

    void setMonth(int m) {
        if (m > 0 && m <= 12) {
            month = m;
        }
        else {
            month = 0;
        }
    }

    void setYear(int y) {
        year = y;  // Assuming no validation for year
    }

    void PrinDat() const {
        std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
    }
};


