#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void calculateTransportation();
void calculateElectricity();
void calculateWaste();
void displayIntro();
void displayOptions();

int main() {
    displayIntro();
    char choice;

    do {
        displayOptions();
        cout << "\nEnter your choice (1-3) or Q to quit: ";
        cin >> choice;

        switch (choice) {
            case '1':
                calculateTransportation();
                break;
            case '2':
                calculateElectricity();
                break;
            case '3':
                calculateWaste();
                break;
            case 'Q':
            case 'q':
                cout << "\nThank you for using the Carbon Footprint Calculator! Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice, please try again.\n";
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}

// Function to display the introductory design
void displayIntro() {
    cout << "********************************************\n";
    cout << "*                                          *\n";
    cout << "*       Welcome to the Carbon Footprint    *\n";
    cout << "*              Calculator!                 *\n";
    cout << "*                                          *\n";
    cout << "********************************************\n\n";
}

// Function to display the options for calculation
void displayOptions() {
    cout << "Choose an activity to calculate its carbon footprint:\n";
    cout << "1. Transportation\n";
    cout << "2. Electricity Usage\n";
    cout << "3. Waste Management\n";
}

// Function to calculate transportation carbon footprint
void calculateTransportation() {
    double milesDriven, fuelEfficiency, carbonFootprint;
    const double CO2_PER_GALLON = 19.6; // pounds of CO2 per gallon of gasoline

    cout << "\nEnter miles driven: ";
    cin >> milesDriven;
    cout << "Enter your vehicle's fuel efficiency (miles per gallon): ";
    cin >> fuelEfficiency;

    carbonFootprint = (milesDriven / fuelEfficiency) * CO2_PER_GALLON;

    cout << fixed << setprecision(2);
    cout << "Your transportation carbon footprint is: " << carbonFootprint << " pounds of CO2\n";
}

// Function to calculate electricity usage carbon footprint
void calculateElectricity() {
    double kWhUsed, carbonFootprint;
    const double CO2_PER_KWH = 0.92; // pounds of CO2 per kWh

    cout << "\nEnter electricity used (kWh): ";
    cin >> kWhUsed;

    carbonFootprint = kWhUsed * CO2_PER_KWH;

    cout << fixed << setprecision(2);
    cout << "Your electricity usage carbon footprint is: " << carbonFootprint << " pounds of CO2\n";
}

// Function to calculate waste management carbon footprint
void calculateWaste() {
    int numPeople;
    double carbonFootprint;
    const double CO2_PER_PERSON = 692; // pounds of CO2 per person per year

    cout << "\nEnter number of people in your household: ";
    cin >> numPeople;

    carbonFootprint = numPeople * CO2_PER_PERSON;

    cout << fixed << setprecision(2);
    cout << "Your waste management carbon footprint is: " << carbonFootprint << " pounds of CO2 per year\n";
}
