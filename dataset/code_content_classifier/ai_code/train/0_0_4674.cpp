#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    int min = 0, max = 0;

    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            N /= i;
            min++;
            max++;
        }
    }
    
    if (N > 1) {
        min++;
        max++;
    }

    cout << min << " " << max << endl;

    return 0;
} 

// Input: 18
// Output: 2 5

// Input: 99
// Output: 2 3

// Input: 10000000019
// Output: 1 1