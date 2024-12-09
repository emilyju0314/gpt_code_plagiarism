#include <iostream>

using namespace std;

// Function to count the number of divisors for a given number
int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;

    int num = 1;
    while (countDivisors(num) != N) {
        num++;
    }

    cout << num << endl;

    return 0;
}