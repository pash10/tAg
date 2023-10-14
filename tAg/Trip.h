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


    Trip(int tripID, char* destination, Date date) {
        setTripNum(tripID);
        setTarget(destination);
        setDate(date);
    }

    Trip(Trip& trip) {
        setTripNum(trip.getTripNum());
        setTarget(trip.getTarget());
        setDate(trip.getDate());
    }
    \

        /*Trip(const Trip& trip) {
            setTripNum(trip.getTripNum());
            target = new char[std::strlen(trip.target) + 1];
            strcpy_s(target, std::strlen(trip.target) + 1, trip.target);
            setDate(trip.getDate());
            setDate(trip.getDate());
        }*/


        Trip() : TripNum(420), date(1, 2, 3) {
        target = new char[3];  // Allocating memory for "hi" and the null terminator
        strcpy_s(target, 3, "hi");
    }

    




    // Getter functions
    int getTripNum() {
        return this->TripNum;
    }
    char* getTarget() {
        return this->target;
    }
    const Date getDate() {
        return this->date;
    }

    // Setter functions
    void setTripNum(int tripId) {
        if (tripId <= 0) {
            this->TripNum = 1; //default value
        }
        else {
            this->TripNum = tripId;
        }
    }

    void setTarget(const char* destination) {
        
        if (isLetters(destination)) {
            target = new char[std::strlen(destination) + 1];
            strcpy_s(target, std::strlen(destination) + 1, destination);
            this->target[std::strlen(target)] = '\0';
            
        }
        else {
            target = new char[3];
            strcpy_s(target, 3, "hi");
        }
        
    }

    bool isLetters(const char* temp) const {
        for (size_t i = 0; i < std::strlen(temp); i++) {  // Use < instead of <=
            if (!isalpha(temp[i])) {
                return false;
            }
        }
        return true;
    }

     void setDate(const Date& d) {
        date = d;
    }
    void printTrip() const {
        std::cout << "Trip Number: " << TripNum << std::endl;
        std::cout << "Target: " << target << std::endl;
        date.PrinDat();
    }



};
#endif