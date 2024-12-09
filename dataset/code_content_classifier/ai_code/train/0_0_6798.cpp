#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    if (exp == 0) return 1;
    long long half = power(base, exp / 2) % MOD;
    long long result = (half * half) % MOD;
    if (exp % 2 == 1) result = (result * base) % MOD;
    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
    for (int i = k; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int aij;
            std::cin >> aij;
            graph[i][aij - 1] = graph[aij - 1][i] = 1;
        }
    }

    std::vector<int> degree(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            degree[i] += graph[i][j];
        }
    }

    std::vector<std::vector<long long>> laplacian(n, std::vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            laplacian[i][j] = (i == j) ? degree[i] : -graph[i][j];
        }
    }

    long long det = 1;
    for (int i = 1; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::abs(laplacian[j][i - 1]) > std::abs(laplacian[pivot][i - 1])) {
                pivot = j;
            }
        }

        if (pivot != i) {
            for (int j = 0; j < n; ++j) {
                std::swap(laplacian[i][j], laplacian[pivot][j]);
            }
            det = (MOD - det) % MOD;
        }

        det = (det * laplacian[i][i - 1]) % MOD;

        long long inv = power(laplacian[i][i - 1], MOD - 2);
        for (int j = 0; j < n; ++j) {
            laplacian[i][j] = (laplacian[i][j] * inv) % MOD;
        }

        for (int j = i + 1; j < n; ++j) {
            long long coef = laplacian[j][i - 1];
            for (int k = 0; k < n; ++k) {
                laplacian[j][k] -= (coef * laplacian[i][k]) % MOD;
                if (laplacian[j][k] < 0) laplacian[j][k] += MOD;
            }
        }
    }

    std::cout << det << std::endl;

    return 0;
}