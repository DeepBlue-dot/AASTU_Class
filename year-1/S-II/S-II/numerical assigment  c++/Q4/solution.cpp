#include <iostream>
#include <cmath>

int main() {
    double x1 = 0, x2 = 0, x3 = 0; // Initial guesses
    double x1_old, x2_old, x3_old;
    double tolerance = 1e-6; // Convergence tolerance
    int maxIterations = 100; // Maximum number of iterations
    int iteration = 0;

    do {
        x1_old = x1;
        x2_old = x2;
        x3_old = x3;

        // Update x1, x2, x3 using the previous values
        x1 = (8.57 - 2*x2_old - x3_old) / 4;
        x2 = (10 - 6.25*x1 - x3_old) / 2.5;
        x3 = 12 - 9*x1 - 3*x2;

        iteration++;
    } while ((std::abs(x1 - x1_old) > tolerance || std::abs(x2 - x2_old) > tolerance || std::abs(x3 - x3_old) > tolerance) && iteration < maxIterations);

    std::cout << "Solution after " << iteration << " iterations:" << std::endl;
    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;
    std::cout << "x3 = " << x3 << std::endl;

    return 0;
}
