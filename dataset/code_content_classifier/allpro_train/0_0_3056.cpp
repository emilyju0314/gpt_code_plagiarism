#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Define a matrix class for matrix multiplication
class Matrix {
public:
    vector<vector<long long>> mat;

    Matrix(int n) {
        mat.assign(n, vector<long long>(n, 0));
    }

    Matrix operator*(const Matrix& other) const {
        int n = mat.size();
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j] % MOD) % MOD;
                }
            }
        }
        return res;
    }
};

// Function to raise a matrix to the power of k
Matrix matrixExponentiation(Matrix base, long long k) {
    int n = base.mat.size();
    Matrix result(n);

    for (int i = 0; i < n; i++) {
        result.mat[i][i] = 1;
    }

    while (k > 0) {
        if (k % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        k /= 2;
    }

    return result;
}

int main() {
    long long k;
    int m;
    cin >> k >> m;

    string fib = "ab"; // Fibonacci string
    string s[m];
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    Matrix transitions(2);
    transitions.mat[0][0] = 1;
    transitions.mat[0][1] = 1;
    transitions.mat[1][0] = 1;

    // Raise transitions matrix to the power of k-1
    Matrix result = matrixExponentiation(transitions, k - 1);

    for (int i = 0; i < m; i++) {
        long long cntA = 0, cntB = 0;
        for (char c : s[i]) {
            if (c == 'a') cntA++;
            else cntB++;
        }

        long long ans = (result.mat[0][0] * cntA + result.mat[0][1] * cntB) % MOD;
        cout << ans << endl;
    }

    return 0;
}