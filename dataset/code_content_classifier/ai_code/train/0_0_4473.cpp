#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n >= 27) {
        cout << m << endl;
    } else {
        int exp = 1<<n; // Calculate 2^n
        cout << m % exp << endl;
    }

    return 0;
}