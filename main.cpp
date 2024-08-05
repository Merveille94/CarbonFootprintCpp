//
// Created by Manue on 05/05/2024.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

void displayIntro() {
    std::cout << R"(
    ╔═══════════════════════════════════════════╗
    ║                                           ║
    ║       🌍 Carbon Footprint Calculator 🌿    ║
    ║                                           ║
    ║     Measure Your Impact on the Planet     ║
    ║                                           ║
    ╚═══════════════════════════════════════════╝
    )" << std::endl;
}

double calculateHomeEnergy() {
    double electricity, gas;
    std::cout << "Enter monthly electricity usage (kWh): ";
    std::cin >> electricity;
    std::cout << "Enter monthly gas usage (therms): ";
    std::cin >> gas;
    return (electricity * 0.92 + gas * 11.7) / 2204.62; // Convert to metric tons CO2
}

double calculateTransportation() {
    double miles;
    int vehicleType;
    std::cout << "Enter annual miles driven: ";
    std::cin >> miles;
    std::cout << "Select vehicle type:\n1. Gasoline car\n2. Hybrid\n3. Electric\n";
    std::cin >> vehicleType;

    switch(vehicleType) {
        case 1: return miles * 0.000403; // metric tons CO2 per mile
        case 2: return miles * 0.000257;
        case 3: return miles * 0.000096;
        default: return 0;
    }
}

double calculateDiet() {
    int dietType;
    std::cout << "Select your diet:\n1. Meat lover\n2. Average\n3. Vegetarian\n4. Vegan\n";
    std::cin >> dietType;

    switch(dietType) {
        case 1: return 3.3;
        case 2: return 2.5;
        case 3: return 1.7;
        case 4: return 1.5;
        default: return 0;
    }
}

int main() {
    displayIntro();

    std::vector<std::pair<std::string, double>> results;
    char choice;
    double total = 0;

    do {
        std::cout << "\nChoose a category to calculate:\n";
        std::cout << "1. Home Energy\n2. Transportation\n3. Diet\n4. Calculate Total\n5. Exit\n";
        std::cin >> choice;

        switch(choice) {
            case '1': {
                double result = calculateHomeEnergy();
                results.push_back({"Home Energy", result});
                total += result;
                break;
            }
            case '2': {
                double result = calculateTransportation();
                results.push_back({"Transportation", result});
                total += result;
                break;
            }
            case '3': {
                double result = calculateDiet();
                results.push_back({"Diet", result});
                total += result;
                break;
            }
            case '4': {
                std::cout << "\n🌳 Your Carbon Footprint Breakdown 🌳\n";
                std::cout << "======================================\n";
                for (const auto& result : results) {
                    std::cout << result.first << ": " << std::fixed << std::setprecision(2)
                              << result.second << " metric tons CO2/year\n";
                }
                std::cout << "======================================\n";
                std::cout << "Total: " << std::fixed << std::setprecision(2)
                          << total << " metric tons CO2/year\n";

                double avgUS = 16.0; // Average US carbon footprint
                std::cout << "\nYour footprint is " << (total / avgUS * 100)
                          << "% of the average US footprint.\n";
                break;
            }
            case '5':
                std::cout << "Thank you for using the Carbon Footprint Calculator!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (true);

    return 0;
}
