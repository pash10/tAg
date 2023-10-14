#ifndef TRIP_H
#define TRIP_H

#include <iostream>
#include <cstring>  // For std::strlen and std::strcpy
#include "data.h"

constexpr auto tripDestinationLength = 420;

class Trip {
private:
    int TripNum;
    char* target;
    Date date;

public:  // Only one public specifier is needed
    

    Trip(int tripID, char * destination[], Date date) {
        setTripNum(tripID);
        setTarget(*destination);
        setDate(date);
    }

    Trip(Trip& trip) {
        setTripNum(trip.getTripNum());
        setTarget(trip.getTarget());
        setDate(trip.getDate());
    }

    Trip() : TripNum(420), date(1, 2, 3) {
        target = new char[3];  // Allocating memory for "hi" and the null terminator
        strcpy_s(target,3, "hi");
    }
   


    // Getter functions
    int getTripNum() const { return TripNum; }
     char* getTarget(){
        return target;
    }
    const Date getDate()  { return date; }

    // Setter functions
    void setTripNum(int t) {
        if (t <= 0) {
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
            strcpy_s(target, std::strlen(to) + 1, to);
        }
        else {
            target = new char[3];  // Allocating memory for "hi" and the null terminator
            strcpy_s(target,3, "hi");
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
#endif