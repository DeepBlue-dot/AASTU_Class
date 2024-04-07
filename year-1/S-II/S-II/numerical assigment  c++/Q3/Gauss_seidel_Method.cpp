#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // Define the coefficient matrix A and the constant vector B
    double A[6][6] = {
        {0.7460, -0.4516, 0.0100, -0.0080, 0.0100, -0.0080},
        {0.4516, 0.7460, 0.0080, -0.0100, 0.0080, -0.0100},
        {-0.0100, -0.00787, -0.5205, -0.00100, 0.00100, -0.00604},
        {0.00100, 0.00100, 0.5205, 0.7787, 0.00800, 0.0100},
        {-0.00800, 0.00100, -0.010, -0.00800, 0.8080, -0.6040},
        {0.00800, 0.00100, 0.0800, 0.1000, 0.6040, 0.8080}
    };
    double B[6] = {120, 0, -60.39, -60, -103.9, 103.9};

    // Initial guess for the solution
    double X[6] = {0};

    // Gauss-Seidel iteration
    for (int iter = 0; iter < 100; ++iter) {  // Maximum 100 iterations
        bool converge = true;
        for (int i = 0; i < 6; ++i) {
            double sum = 0.0;
            for (int j = 0; j < 6; ++j) {
                if (j != i) {
                    sum += A[i][j] * X[j];
                }
            }
            double X_new = (B[i] - sum) / A[i][i];
            if (std::abs(X_new - X[i]) > 1e-8) {
                converge = false;
            }
            X[i] = X_new;
        }
        if (converge) {
            break;
        }
    }

    // Print the solution
    std::cout << "Solution: ";
    for (double x : X) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
