#include <iostream>

#include "Trip.h"
#include "data.h"

using namespace std; // foregt to add std to data and trip f

/*
bool isEmpty(int size);
void Print(Trip* arr, int size);
void EditTrip(Trip* arr, int size);
Trip* AddTrip(Trip* arr, int size);
*/

bool isEmpty(int size) {
    return size == 0;
}

void Print(Trip* arr, int size) {
    if (isEmpty(size)) {
        cout << "No Trips" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("================\nTrip Number: %d.\n", i);
        arr[i].getDate().PrinDat();
        printf("\n");
        cout << arr[i].getTripNum() << ", " << arr[i].getTarget() << endl;
        printf("================\n");
    }
}

void EditTrip(Trip* arr, int size) {
    if (isEmpty(size)) {
        cout << "No Trips" << endl;
        return;
    }

    Date newDate;

    int op;
    while (true) {
        cout << "Select the index to Edit" << endl;
        cin >> op;

        if (op < 0 || op > size) {
            cout << op << " is out of range, try again" << endl;
            continue;
        }

        cout << "Edit new Trip Id" << endl;
        int newTripId;
        cin >> newTripId;

        cout << "Edit new Destination" << endl;
        char newDestination[tripDestinationLength];
        cin.ignore(); //ingore weird input buffers
        cin.getline(newDestination, tripDestinationLength);

        int year, month, day;

        cout << "edit new Year: " << endl;
        cin >> year;

        cout << "edit new Month: " << endl;
        cin >> month;

        cout << "edit new Day: " << endl;
        cin >> day;

        arr[op].setTripNum(newTripId);
        arr[op].setTarget(newDestination);

        newDate.setYear(year);
        newDate.setMonth(month);
        newDate.setDay(day);
        arr[op].setDate(newDate);

        break;
    }
}

Trip* AddTrip(Trip* arr, int size) {
    Trip* newTrip = arr;

    int newTripId;

    char newDestination[tripDestinationLength];

    Date newDate;

    cout << "Enter new Trip Id: " << endl;
    cin >> newTripId;

    cout << "Enter new Destination: " << endl;
    cin.ignore(); //ingore weird input buffers
    cin.getline(newDestination, tripDestinationLength);

    int year, month, day;

    cout << "Enter new Year: " << endl;
    cin >> year;

    cout << "Enter new Month: " << endl;
    cin >> month;

    cout << "Enter new Day: " << endl;
    cin >> day;

    newTrip[size].setTripNum(newTripId);

    newTrip[size].setTarget(newDestination);

    newDate.setYear(year);

    newDate.setMonth(month);

    newDate.setDay(day);

    newTrip[size].setDate(newDate);

    return newTrip;
}

int main()
{
    int option;
    Trip* arr = new Trip[0];
    int size = 0;
    do {
        cout << "Please Select an option: \n1. Print Trip \n2. Edit Trip \n3. Add Trip \n4. Exit" << endl;
        cin >> option;
        switch (option) {
        case 1:
            Print(arr, size);
            break;
        case 2:
            EditTrip(arr, size);
            break;
        case 3:
            arr = AddTrip(arr, size);
            size++;
            break;
        case 4:
            cout << "bye bye!" << endl;
            break;
        default:
            cout << "Invalid option!" << endl;
            return 1;
        }
    } while (option != 4);

    delete[] arr;

    return 0;
}