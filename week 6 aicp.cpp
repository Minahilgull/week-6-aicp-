#include <iostream>
using namespace std;

// Function to check a single sack
bool checkSingleSack(char content, double weight) {
    if ((content == 'C' && weight >= 24.9 && weight <= 25.1) ||
        ((content == 'G' || content == 'S') && weight >= 49.9 && weight <= 50.1)) {
        return true;
    } else {
        cout << "Rejected: ";
        if (content != 'C' && content != 'G' && content != 'S') {
            cout << "Invalid contents. ";
        }
        if ((content == 'C' && (weight < 24.9 || weight > 25.1)) ||
            ((content == 'G' || content == 'S') && (weight < 49.9 || weight > 50.1))) {
            cout << "Invalid weight.";
        }
        cout << endl;
        return false;
    }
}

// Function to check a customer's order
void checkCustomerOrder(int numCement, int numGravel, int numSand) {
    int rejectedSacks = 0;
    double totalWeight = 0;

    // Check each sack in the order
    rejectedSacks += !checkSingleSack('C', numCement * 25.0); // assuming average weight
    rejectedSacks += !checkSingleSack('G', numGravel * 50.0); // assuming average weight
    rejectedSacks += !checkSingleSack('S', numSand * 50.0); // assuming average weight

    // Calculate total weight
    totalWeight = (numCement * 25.0) + (numGravel * 50.0) + (numSand * 50.0);

    cout << "Total weight of the order: " << totalWeight << " kilograms." << endl;
    cout << "Number of rejected sacks: " << rejectedSacks << endl;
}

// Function to calculate the price for a customer's order
void calculateOrderPrice(int numCement, int numGravel, int numSand) {
    const double cementPrice = 3.0;
    const double gravelPrice = 2.0;
    const double sandPrice = 2.0;
    const double specialPackPrice = 10.0;

    double regularPrice = (numCement * cementPrice) + (numGravel * gravelPrice) + (numSand * sandPrice);

    // Check for special packs
    int numSpecialPacks = min(numCement, min(numGravel / 2, numSand / 2));

    double totalPrice;
    if (numSpecialPacks > 0) {
        totalPrice = regularPrice - (numSpecialPacks * (cementPrice + 2 * sandPrice + 2 * gravelPrice)) + (numSpecialPacks * specialPackPrice);
        cout << "Special packs applied! New price: $" << totalPrice << endl;
        cout << "You saved: $" << (regularPrice - totalPrice) << endl;
    } else {
        cout << "Regular price: $" << regularPrice << endl;
    }
}

int main() {
    // Task 1
    char sackContent;
    double sackWeight;

    cout << "Task 1 - Check a single sack:" << endl;
    cout << "Enter sack content (C, G, S): ";
    cin >> sackContent;
    cout << "Enter sack weight: ";
    cin >> sackWeight;

    if (checkSingleSack(sackContent, sackWeight)) {
        cout << "Accepted: Contents - " << sackContent << ", Weight - " << sackWeight << " kilograms." << endl;
    }

    // Task 2
    int numCement, numGravel, numSand;

    cout << "\nTask 2 - Check a customer's order:" << endl;
    cout << "Enter number of cement sacks: ";
    cin >> numCement;
    cout << "Enter number of gravel sacks: ";
    cin >> numGravel;
    cout << "Enter number of sand sacks: ";
    cin >> numSand;

    checkCustomerOrder(numCement, numGravel, numSand);

    // Task 3
    cout << "\nTask 3 - Calculate the price for a customer's order:" << endl;
    calculateOrderPrice(numCement, numGravel, numSand);

    return 0;
}

