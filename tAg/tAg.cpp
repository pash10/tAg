#include "Trip.h"  // Assuming you've saved your Trip class in a file named "Trip.h"
#include "data.h"  // Assuming "data.h" contains the definition for the Date class

int main() {
    // Creating a date object
    Date sampleDate(1, 10, 2023);

    // Creating a trip object using default constructor
    Trip defaultTrip;
    std::cout << "=== Default Trip ===" << std::endl;
    defaultTrip.printTrip();

    // Creating a trip object using parameterized constructor
    Trip myTrip(100, "Vacation", sampleDate);
    std::cout << "\n=== My Trip (Before Modification) ===" << std::endl;
    myTrip.printTrip();

    // Modifying trip details using setter functions
    myTrip.setTripNum(500);
    myTrip.setTarget("Holiday");

    // Reprinting modified trip details
    std::cout << "\n=== My Trip (After Modification) ===" << std::endl;
    myTrip.printTrip();

    // Testing with an invalid target (non-letter characters)
    Trip invalidTrip(200, "Trip 2023", sampleDate);
    std::cout << "\n=== Invalid Trip ===" << std::endl;
    invalidTrip.printTrip();  // Should print the default "hi" for target

    return 0;
}
