// The following program allows the user to calculate savings based on interest rates and annual deposits
#include <iostream>
#include <cmath>

using namespace std;

// Calculates savings without annual deposits for a range of interest rates
void calculateSavingsWithoutAnnualDeposits(double* principal, double* min_interest_rate, double* max_interest_rate, int* num_years) 
{
    // Loop through all interest rates in the given range
    for (double i = *min_interest_rate; i <= *max_interest_rate; i += 0.01) 
    {
        double balance = *principal;
        // Calculate the balance for each year based on the current interest rate
        for (int j = 1; j <= *num_years; j++) 
        {
            balance *= (1 + i);
            cout << "Year " << j << ": " << balance << endl;
        }
        cout << endl;
    }
}

// Calculates savings with annual deposits for a range of interest rates
void calculateSavingsWithAnnualDeposits(double* principal, double* min_interest_rate, double* max_interest_rate, int* num_years, double* annual_deposit)
 {
    // Loop through all interest rates in the given range
    for (double i = *min_interest_rate; i <= *max_interest_rate; i += 0.01)
    {
        double balance = *principal;
        // Calculate the balance for each year based on the current interest rate and annual deposit amount
        for (int j = 1; j <= *num_years; j++)
        {
            balance *= (1 + i);
            balance += *annual_deposit;
            cout << "Year " << j << ": " << balance << endl;
        }
        cout << endl;
    }
}

int main() {
    int choice;
    double principal, min_interest_rate, max_interest_rate, annual_deposit;
    int num_years;

    // Display menu and get user choice
    cout << "Choose an option:" << endl;
    cout << "1. Calculate savings without annual deposits" << endl;
    cout << "2. Calculate savings with annual deposits" << endl;
    cin >> choice;

    switch (choice) 
    {
        case 1:
            // Get user input for principal, interest rates, and number of years
            cout << "Enter principal: ";
            cin >> principal;
            cout << "Enter minimum interest rate: ";
            cin >> min_interest_rate;
            cout << "Enter maximum interest rate: ";
            cin >> max_interest_rate;
            cout << "Enter number of years: ";
            cin >> num_years;

            // Call function to calculate savings without annual deposits
            calculateSavingsWithoutAnnualDeposits(&principal, &min_interest_rate, &max_interest_rate, &num_years);

            break;

        case 2:
            // Get user input for principal, interest rates, number of years, and annual deposit amount
            cout << "Enter principal: ";
            cin >> principal;
            cout << "Enter minimum interest rate: ";
            cin >> min_interest_rate;
            cout << "Enter maximum interest rate: ";
            cin >> max_interest_rate;
            cout << "Enter number of years: ";
            cin >> num_years;
            cout << "Enter annual deposit amount: ";
            cin >> annual_deposit;

            // Call function to calculate savings with annual deposits
            calculateSavingsWithAnnualDeposits(&principal, &min_interest_rate, &max_interest_rate, &num_years, &annual_deposit);

            break;

        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}