#include <iostream>
#include <vector>

int main() {
    // Define the coefficient matrix A and the constant vector B
    std::vector<std::vector<double>> A = {
        {0.7460, -0.4516, 0.0100, -0.0080, 0.0100, -0.0080},
        {0.4516, 0.7460, 0.0080, -0.0100, 0.0080, -0.0100},
        {-0.0100, -0.00787, -0.5205, -0.00100, 0.00100, -0.00604},
        {0.00100, 0.00100, 0.5205, 0.7787, 0.00800, 0.0100},
        {-0.00800, 0.00100, -0.010, -0.00800, 0.8080, -0.6040},
        {0.00800, 0.00100, 0.0800, 0.1000, 0.6040, 0.8080}
    };
    std::vector<double> B = {120, 0, -60.39, -60, -103.9, 103.9};

    // Augment the matrix A with B
    std::vector<std::vector<double>> AB(A.size(), std::vector<double>(A[0].size() + 1));
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            AB[i][j] = A[i][j];
        }
        AB[i][A[0].size()] = B[i];
    }

    int n = B.size();

    // Naive Gauss Elimination
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double m = AB[j][i] / AB[i][i];
            for (int k = i; k <= n; ++k) {
                AB[j][k] -= m * AB[i][k];
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            double m = AB[j][i] / AB[i][i];
            for (int k = i; k <= n; ++k) {
                AB[j][k] -= m * AB[i][k];
            }
        }
    }

    std::vector<double> X(n);
    for (int i = 0; i < n; ++i) {
        X[i] = AB[i][n] / AB[i][i];
    }

    // Print the solution
    std::cout << "Solution: ";
    for (double x : X) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
