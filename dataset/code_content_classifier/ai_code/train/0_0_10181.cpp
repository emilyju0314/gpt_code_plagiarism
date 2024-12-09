#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int k = ((a + b) % n + n) % n; // Calculate the entrance where Vasya will be at the end of his walk

    if (k == 0) {
        k = n; // If the result is 0, set it to n
    }

    cout << k;

    return 0;
}