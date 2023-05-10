#include <iostream>
#include <string> 
#include <cctype>
#include <algorithm>    
#include <cmath>

using std::cout;
using std::cin;

void calc_investment();
void calc_bond();

int main() {
    cout << "WELCOME\n-------\n";
    
    int type;
    cout << "\nPlease select an investment type: ";
    cout << "\n---------------------------------";
    cout << "\n1. INVESTMENT - to calculate the amount of interest you'll earn on your investment.";
    cout << "\n2. BOND        - to calculate the amount you'll have to pay on a home loan";
    cout << "\nEnter the option number: ";
    if (!(cin >> type)){
        cout << "\nInvalid Input. Exiting Program...";
            return 1;
    }
    
    switch(type){
    case 1: 
        calc_investment();
        break;
    case 2:
        calc_bond();
        break;
    default: 
        cout << "Invalid Option. Exiting Program..."; 
    }


    return 0;
}

void calc_investment() {
    cout << "\nInvestment Calculator";
    cout << "\n---------------------\n\n";

    float initAmount, interest;
    int years;

    cout << "How much money are you depositing? £";
    if (!(cin >> initAmount)) {
        cout << "Invalid Input detected! Exiting program...";
        return;
    }
    cout << "Enter the interest rate as a %: ";
    if (!(cin >> interest)) {
        cout << "Invalid Input detected! Exiting program...";
        return;
    }
    cout << "Enter the total length of investment (in years): ";
    if (!(cin >> years)) {
        cout << "Invalid Input detected! Exiting program...";
        return;
    }

    float finalAmount;
    std::string type;
    while (true) {
        cout << "Do you want 'simple' or 'compound' interest? ";
        cin >> type;
        std::transform(type.begin(), type.end(), type.begin(), [](unsigned char c){return std::tolower(c);});
        if (type == "simple") {
            finalAmount = initAmount * (1 + (interest / 100) * years);
            break;
        }
        else if (type == "compound") {
            finalAmount = initAmount * pow(1 + (interest / 100), years);
            break;
        }
        else {
            cout << "Invalid input! Please type either 'simple' or 'compound'.\n\n";
        }
    }

    cout << "\nInitial investment:   " << initAmount << '\n';
    cout << "Length of investment: " << years << '\n';
    cout << "Projected earnings:   " << finalAmount;    
}

void calc_bond() {
    cout << "\nBond Calculator";
    cout << "\n---------------";

    float curVal, interest;
    int months;

    cout << "\nEnter the present value: £";
    if (!(cin >> curVal)) {
        cout << "Invalid Input detected! Exiting program...";
        return;
    }
    cout << "Enter the interest rate as a %: ";
    if (!(cin >> interest)) {
        cout << "Invalid Input detected! Exiting program...";
        return;
    }
    else {
        interest = (interest / 100) / 12;
    }
    cout << "Enter the number of months you wish to make payments for: ";
    if (!(cin >> months)) {
        cout << "Invalid Input detected! Exiting program...";
        return;
    }

    float repayment = (interest * curVal) / (1- pow((1 + interest), -months));
    cout << "\nMonthly repayments: £" << repayment;

}