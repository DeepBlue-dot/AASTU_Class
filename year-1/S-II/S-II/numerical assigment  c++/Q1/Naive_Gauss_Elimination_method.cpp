#include <iostream>
#include <vector>

// Define the coefficient matrix A and the constant vector B
std::vector<std::vector<double>> A = {
    {24, -2860, 7.26e5},
    {-2860, 7.26e5, -1.86472e8},
    {7.26e5, -1.86472e8, 5.24357e10}
};

std::vector<double> B = {1.057e-4, -1.04162e-2, 2.56799};

// Naïve Gauss Elimination Method
std::vector<double> gauss_elimination(const std::vector<std::vector<double>>& A,
                                      const std::vector<double>& B) {
    int n = B.size();
    std::vector<std::vector<double>> augmented_matrix(A);
    for (int i = 0; i < n; ++i) {
        augmented_matrix[i].push_back(B[i]);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = k + 1; i < n; ++i) {
            double factor = augmented_matrix[i][k] / augmented_matrix[k][k];
            for (int j = k; j <= n; ++j) {
                augmented_matrix[i][j] -= factor * augmented_matrix[k][j];
            }
        }
    }

    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += augmented_matrix[i][j] * x[j];
        }
        x[i] = (augmented_matrix[i][n] - sum) / augmented_matrix[i][i];
    }

    return x;
}

int main() {
    std::vector<double> solution = gauss_elimination(A, B);

    std::cout << "The solution is:" << std::endl;
    std::cout << "a1 = " << solution[0] << std::endl;
    std::cout << "a2 = " << solution[1] << std::endl;
    std::cout << "a3 = " << solution[2] << std::endl;

    return 0;
}
