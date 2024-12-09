#include <iostream>
#include <vector>

using namespace std;

// Function to calculate factorial
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Function to calculate the lowest prime divisor
int lowestPrimeDivisor(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return i;
        }
    }
    return x;
}

int main() {
    int n;
    cin >> n;

    vector<int> fragments(n);
    for (int i = 0; i < n; i++) {
        cin >> fragments[i];
    }

    int min_path_sum = 0;
    for (int i = 0; i < n; i++) {
        int node = factorial(fragments[i]);

        while (node > 1) {
            int div = lowestPrimeDivisor(node);
            min_path_sum += (node / div);
            node /= div;
        }
    }

    cout << min_path_sum << endl;

    return 0;
}