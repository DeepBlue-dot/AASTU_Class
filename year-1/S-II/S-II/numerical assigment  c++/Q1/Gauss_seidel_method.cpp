#include <iostream>
#include <vector>

// Define the coefficient matrix A and the constant vector B
std::vector<std::vector<double>> A = {
    {24, -2860, 7.26e5},
    {-2860, 7.26e5, -1.86472e8},
    {7.26e5, -1.86472e8, 5.24357e10}
};

std::vector<double> B = {1.057e-4, -1.04162e-2, 2.56799};

// Gauss-Seidel method
std::vector<double> gauss_seidel(const std::vector<std::vector<double>>& A,
                                 const std::vector<double>& B,
                                 double tolerance = 1e-10,
                                 int max_iterations = 1000) {
    int n = A.size();
    std::vector<double> x(n, 0.0);

    for (int iter = 0; iter < max_iterations; ++iter) {
        std::vector<double> x_new = x;
        for (int i = 0; i < n; ++i) {
            double s1 = 0.0;
            for (int j = 0; j < i; ++j) {
                s1 += A[i][j] * x_new[j];
            }
            double s2 = 0.0;
            for (int j = i + 1; j < n; ++j) {
                s2 += A[i][j] * x[j];
            }
            x_new[i] = (B[i] - s1 - s2) / A[i][i];
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

    std::cout << "The solution is:" << std::endl;
    std::cout << "a1 = " << solution[0] << std::endl;
    std::cout << "a2 = " << solution[1] << std::endl;
    std::cout << "a3 = " << solution[2] << std::endl;

    return 0;
}
