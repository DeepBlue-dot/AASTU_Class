#include <iostream>
#include <vector>

// Define the coefficient matrix A and the constant vector B
std::vector<std::vector<double>> A = {
    {0.3333, 0.1667, 0.6667},
    {0.1667, 0.6667, 0.3333},
    {1.05, -1.00, 0}
};

std::vector<double> B = {756, 1260, 0};

// LU Decomposition using scipy.linalg.lu_factor and lu_solve
std::vector<double> lu_decomposition(const std::vector<std::vector<double>>& A,
                                     const std::vector<double>& B) {
    int n = B.size();
    std::vector<double> x(n, 0.0);

    // Factorize the matrix A into the LU decomposition
    std::vector<std::vector<double>> lu = A;
    std::vector<int> piv(n);
    for (int i = 0; i < n; ++i) {
        piv[i] = i;
    }

    for (int k = 0; k < n; ++k) {
        double max_val = 0.0;
        int max_row = k;
        for (int i = k; i < n; ++i) {
            if (std::abs(lu[i][k]) > max_val) {
                max_val = std::abs(lu[i][k]);
                max_row = i;
            }
        }

        if (max_row != k) {
            std::swap(lu[k], lu[max_row]);
            std::swap(piv[k], piv[max_row]);
        }

        for (int i = k + 1; i < n; ++i) {
            lu[i][k] /= lu[k][k];
            for (int j = k + 1; j < n; ++j) {
                lu[i][j] -= lu[i][k] * lu[k][j];
            }
        }
    }

    // Solve the system of equations using the LU decomposition
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < i; ++j) {
            sum += lu[i][j] * x[j];
        }
        x[i] = B[piv[i]] - sum;
    }

    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += lu[i][j] * x[j];
        }
        x[i] = (x[i] - sum) / lu[i][i];
    }

    return x;
}

int main() {
    std::vector<double> solution = lu_decomposition(A, B);

    std::cout << "Solution using LU Decomposition:" << std::endl;
    std::cout << "x1 (toys for boys): " << solution[0] << std::endl;
    std::cout << "x2 (toys for girls): " << solution[1] << std::endl;
    std::cout << "x3 (unisexual toys): " << solution[2] << std::endl;

    return 0;
}
