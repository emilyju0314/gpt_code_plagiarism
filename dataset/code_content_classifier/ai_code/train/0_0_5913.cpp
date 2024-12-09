#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    // Using matrix exponentiation to calculate the number of triangle plants pointing upwards after n years
    // Fibonacci matrix
    long long fib[2][2] = {{0, 1}, {1, 1}};

    // Initializing result matrix as identity matrix
    long long res[2][2] = {{1, 0}, {0, 1}};

    // Matrix exponentiation
    while (n > 0) {
        if (n % 2 == 1) {
            long long temp[2][2];
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    temp[i][j] = 0;
                    for (int k = 0; k < 2; k++) {
                        temp[i][j] += res[i][k] * fib[k][j];
                        temp[i][j] %= 1000000007;
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    res[i][j] = temp[i][j];
                }
            }
        }

        long long temp[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                temp[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    temp[i][j] += fib[i][k] * fib[k][j];
                    temp[i][j] %= 1000000007;
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                fib[i][j] = temp[i][j];
            }
        }

        n /= 2;
    }

    cout << res[0][1] * 3 % 1000000007 << endl;

    return 0;
}