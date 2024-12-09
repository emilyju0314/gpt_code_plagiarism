#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int n;
    cin >> n;

    // Calculate the number of ways to place the benches using combinatorial mathematics
    int ways = factorial(n*n) / (factorial(n) * factorial(n));

    cout << ways << endl;

    return 0;
}