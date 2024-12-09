#include <iostream>
using namespace std;

int reflect(int n) {
    int result = 0;
    while (n > 0) {
        result = result * 10 + (9 - n % 10);
        n /= 10;
    }
    return result;
}

int main() {
    int l, r;
    cin >> l >> r;

    int max_weight = 0;
    for (int i = l; i <= r; i++) {
        int reflection = reflect(i);
        max_weight = max(max_weight, i * reflection);
    }

    cout << max_weight << endl;

    return 0;
}