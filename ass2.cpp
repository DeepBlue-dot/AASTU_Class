#include <iostream>
#include <cmath>

using namespace std;

// Checks if a number is prime
bool isPrime(int* num) 
{
    // Check if the number is divisible by any numbers from 2 to its square root
    for (int i = 2; i <= sqrt(*num); i++) 
    {
        if (*num % i == 0) 
        {
            return false;
        }
    }
    return true;
}

// Finds all prime factors of a number
void findPrimeFactors(int* num) 
{
    cout << "Prime factors of " << *num << " are: ";
    for (int i = 2; i <= *num; i++) 
    {
        while (*num % i == 0) 
        {
            cout << i << " ";
            *num /= i;
        }
        
    }
}

// Calculates the average value of all prime numbers between 1 and the input number
double calculatePrimeAverage(int* num) 
{
    int count = 0;
    double sum = 0;
    // Loop through all numbers between 2 and the input number - 1
    for (int i = 2; i < *num; i++) 
    {
        // Check if each number is prime
        if (isPrime(&i)) 
        {
            sum += i; // If the number is prime, add it to the sum and increment the count
            count++;
        }
    }
    // Calculate the average value of all prime numbers between 1 and the input number
    return sum / count;
}

int main() 
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    if (num < 3)
    {
        cout << num << " is a prime number." << endl;
    }
    else if (!isPrime(&num)) 
    {
        cout << num << " is not a prime number." << endl;
        findPrimeFactors(&num);
    } 
    else 
    {
        cout << num << " is a prime number with an average value of prime numbers between 1 and " 
        << num << " = " << calculatePrimeAverage(&num) << endl;
    }

    return 0;
}