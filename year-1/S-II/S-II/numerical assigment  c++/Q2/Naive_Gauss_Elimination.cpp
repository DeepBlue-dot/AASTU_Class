#include <iostream>
#include <vector>

// Define the naive Gauss elimination method
std::vector<double> gauss_elimination(std::vector<std::vector<double>>& A, std::vector<double>& b) {
    int n = b.size();

    // Forward elimination
    for (int k = 0; k < n - 1; ++k) {
        for (int i = k + 1; i < n; ++i) {
            if (A[i][k] == 0) continue;
            double factor = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= factor * A[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    // Back substitution
    std::vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; --i) {
        double sum_ax = 0;
        for (int j = i + 1; j < n; ++j) {
            sum_ax += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum_ax) / A[i][i];
    }

    return x;
}

int main() {
    // Coefficients matrix
    std::vector<std::vector<double>> A = {{0.3333, 0.1667, 0.6667},
                                          {0.1667, 0.6667, 0.3333},
                                          {1.05, -1.00, 0}};

    // Right-hand side vector
    std::vector<double> b = {756, 1260, 0};

    // Solve the system using naive Gauss elimination
    std::vector<double> solution = gauss_elimination(A, b);

    // Print the solution
    std::cout << "Solution using Naive Gauss Elimination:" << std::endl;
    std::cout << "x1 (toys for boys): " << solution[0] << std::endl;
    std::cout << "x2 (toys for girls): " << solution[1] << std::endl;
    std::cout << "x3 (unisexual toys): " << solution[2] << std::endl;

    return 0;
}
