#include <iostream>
#include <string>

using namespace std;

int S(long long n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

int main() {
    long long w, m, k;
    cin >> w >> m >> k;

    int maxLen = 0;
    for (int i = 1; i < 10; i++) {
        long long cost = S(m+i)*k;
        if (cost <= w) {
            w -= cost;
            maxLen++;
        } else {
            break;
        }
    }

    cout << maxLen << endl;

    return 0;
}