#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> colors(n, 0);
    int color = 1;

    for (int i = 0; i < n; i++) {
        if (!isPrime(i + 1)) {
            colors[i] = color;
            color = color % 2 + 1;  // Alternate between colors 1 and 2
        }
    }

    for (int i = 0; i < n; i++) {
        cout << colors[i] << " ";
    }
    
    return 0;
}