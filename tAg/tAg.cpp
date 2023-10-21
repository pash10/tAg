#include <iostream>

#include "Trip.h"
#include "data.h"

using namespace std; // foregt to add std to data and trip f


bool isEmpty(int size) {
    return size == 0;
}

void Print(Trip* arr, int size) {
    if (isEmpty(size)) {
        cout << "No Trips" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("================\nTrip Number: %d.\n", i+1);
        arr[i].getDate().printDate();
        printf("\n");
        cout << arr[i].getTripNum() << ", " << arr[i].getTarget() << endl;
        printf("================\n");
        arr[i].printCount();
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
        cout << "Select the trip number to Edit" << endl;
        cin >> op;

        if (op -1  < 0 || op -1 > size) {
            cout << op << " is out of range, try again" << endl;
            continue;
        }

       
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

    char newDestination[tripDestinationLength];

    Date newDate;

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
int Trip::count = 0;
