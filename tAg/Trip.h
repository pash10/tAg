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
    static int count;

public:  // Only one public specifier is needed
 

    Trip(char* destination, Date date) {
        TripNum = countBigger();
        setTarget(destination);
        setDate(date);
    }

    Trip(Trip& trip) {
        this->TripNum = trip.getTripNum();
        setTarget(trip.getTarget());
        setDate(trip.getDate());
    }
    

        /*Trip(const Trip& trip) {
            setTripNum(trip.getTripNum());
            target = new char[std::strlen(trip.target) + 1];
            strcpy_s(target, std::strlen(trip.target) + 1, trip.target);
            setDate(trip.getDate());
            setDate(trip.getDate());
        }*/


        Trip() : date(1, 2, 3) {
        TripNum = countBigger();
        target = new char[3];  // Allocating memory for "hi" and the null terminator
        strcpy_s(target, 3, "hi");
    }

        static int countBigger() {
            {
                count++;
                return count;
            }
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
        date.printDate();
    }
    void printCount() const {
        std::cout << "plz " << count << std::endl;
    }



};
#endif