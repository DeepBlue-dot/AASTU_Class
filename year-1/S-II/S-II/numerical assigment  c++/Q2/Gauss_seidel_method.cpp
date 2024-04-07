#include <iostream>
#include <vector>

// Define the coefficient matrix A and the constant vector B
std::vector<std::vector<double>> A = {
    {0.3333, 0.1667, 0.6667},
    {0.1667, 0.6667, 0.3333},
    {1.05, -1.00, 0}
};

std::vector<double> B = {756, 1260, 0};

// Gauss-Seidel method
std::vector<double> gauss_seidel(const std::vector<std::vector<double>>& A,
                                 const std::vector<double>& B,
                                 double tolerance = 1e-10,
                                 int max_iterations = 1000) {
    int n = B.size();
    std::vector<double> x(n, 0.0);

    for (int iter = 0; iter < max_iterations; ++iter) {
        std::vector<double> x_new = x;
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * x_new[j];
                }
            }
            x_new[i] = (B[i] - sum) / A[i][i];
        }

        bool converged = true;
        for (int i = 0; i < n; ++i) {
            if (std::abs(x[i] - x_new[i]) > tolerance) {
                converged = false;
                break;
            }
        }

        if (converged) {
            return x_new;
        }

        x = x_new;
    }

    return x;
}

int main() {
    std::vector<double> solution = gauss_seidel(A, B);

    std::cout << "Solution using Gauss-Seidel Method:" << std::endl;
    std::cout << "x1 (toys for boys): " << solution[0] << std::endl;
    std::cout << "x2 (toys for girls): " << solution[1] << std::endl;
    std::cout << "x3 (unisexual toys): " << solution[2] << std::endl;

    return 0;
}
