#include <iostream>
#include <vector>

using namespace std;

int d(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    long long sum = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                sum = (sum + d(i * j * k)) % 1073741824;
            }
        }
    }

    cout << sum << endl;

    return 0;
}