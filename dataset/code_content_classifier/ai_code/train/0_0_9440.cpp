#include <iostream>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    int count = 0;

    for (int p = 1; p <= N; p++) {
        for (int q = 1; q <= N; q++) {
           if (isPrime(p + q)) {
               count++;
           }
        }
    }

    cout << count << endl;

    return 0;
}