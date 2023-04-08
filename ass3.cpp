#include <iostream>
#include <cmath>

using namespace std;

void calculateSavingsWithoutAnnualDeposits(double* principal, double* min_interest_rate, double* max_interest_rate, int* num_years) 
{
    for (double i = *min_interest_rate; i <= *max_interest_rate; i += 0.01) 
    {
        double balance = *principal;
        for (int j = 1; j <= *num_years; j++) 
        {
            balance *= (1 + i);
            cout << "Year " << j << ": " << balance << endl;
        }
        cout << endl;
    }
}

void calculateSavingsWithAnnualDeposits(double* principal, double* min_interest_rate, double* max_interest_rate, int* num_years, double* annual_deposit) 
{
    for (double i = *min_interest_rate; i <= *max_interest_rate; i += 0.01) 
    {
        double balance = *principal;
        for (int j = 1; j <= *num_years; j++) 
        {
            balance *= (1 + i);
            balance += *annual_deposit;
            cout << "Year " << j << ": " << balance << endl;
        }
        cout << endl;
    }
}

int main() 
{
    int choice;
    double principal, min_interest_rate, max_interest_rate, annual_deposit;
    int num_years;

    cout << "Choose an option:" << endl;
    cout << "1. Calculate savings without annual deposits" << endl;
    cout << "2. Calculate savings with annual deposits" << endl;
    cin >> choice;

    switch (choice) 
    {
        case 1:
            cout << "Enter principal: ";
            cin >> principal;
            cout << "Enter minimum interest rate: ";
            cin >> min_interest_rate;
            cout << "Enter maximum interest rate: ";
            cin >> max_interest_rate;
            cout << "Enter number of years: ";
            cin >> num_years;

            calculateSavingsWithoutAnnualDeposits(&principal, &min_interest_rate, &max_interest_rate, &num_years);

            break;

        case 2:
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

            calculateSavingsWithAnnualDeposits(&principal, &min_interest_rate, &max_interest_rate, &num_years, &annual_deposit);

            break;

        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}