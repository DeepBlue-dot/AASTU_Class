#include <iostream>
#include <vector>

// Define the coefficient matrix A and the constant vector B
std::vector<std::vector<double>> A = {
    {24, -2860, 7.26e5},
    {-2860, 7.26e5, -1.86472e8},
    {7.26e5, -1.86472e8, 5.24357e10}
};

std::vector<double> B = {1.057e-4, -1.04162e-2, 2.56799};

// LU Decomposition using scipy.linalg.lu_factor and lu_solve
std::vector<double> lu_decomposition(const std::vector<std::vector<double>>& A,
                                     const std::vector<double>& B) {
    int n = A.size();
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

    std::cout << "The solution is:" << std::endl;
    std::cout << "a1 = " << solution[0] << std::endl;
    std::cout << "a2 = " << solution[1] << std::endl;
    std::cout << "a3 = " << solution[2] << std::endl;

    return 0;
}
