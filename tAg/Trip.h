#include <iostream>
#include <cstring>  // For std::strlen and std::strcpy
#include "data.h"

class Trip {
private:
    int TripNum;
    char* target;
    Date date;

public:  // Only one public specifier is needed
    Trip() : TripNum(420), date(1, 2, 3) {
        target = new char[3];  // Allocating memory for "hi" and the null terminator
        std::strcpy(target, "hi");
    }

    Trip(int t,const char* to, Date d) : TripNum(t), date(d) {
        setTarget(to);
    }

    Trip& operator=(const Trip& other) {
        if (this == &other) {  // Self-assignment check
            return *this;
        }

        setTarget(other.getTarget());
        setTripNum(other.getTripNum());
        setDate(other.getDate());
        return *this;
    }

    ~Trip() {
        delete[] target;
    }

    // Copy Constructor
    Trip(const Trip& other) : target(NULL) {
        *this = other;  // Using the assignment operator to copy the data
    }

    // Getter functions
    int getTripNum() const { return TripNum; }
    const char* getTarget() const {
        return target;
    }
    Date getDate() const { return date; }

    // Setter functions
    void setTripNum(int t) {
        if (t < 0) {
            TripNum = 420;
        }
        else {
            TripNum = t;
        }
    }

    void setTarget(const char* to) {
        delete[] target;
        if (isLetters(to)) {
            target = new char[std::strlen(to) + 1];
            std::strcpy(target, to);
        }
        else {
            target = new char[3];  // Allocating memory for "hi" and the null terminator
            std::strcpy(target, "hi");
        }
    }

    void setDate(const Date& d) {
        date = d;
    }

    bool isLetters(const char* temp) const {
        for (size_t i = 0; i < std::strlen(temp); i++) {  // Use < instead of <=
            if (!isalpha(temp[i])) {
                return false;
            }
        }
        return true;
    }

    void printTrip() const {
        std::cout << "Trip Number: " << TripNum << std::endl;
        std::cout << "Target: " << target << std::endl;
        date.PrinDat();
    }

   
   
};  
