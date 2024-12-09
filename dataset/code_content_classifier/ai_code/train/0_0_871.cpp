#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> garbage(n);
    for (int i = 0; i < n; i++) {
        cin >> garbage[i];
    }

    long long bags = 0;
    long long current = 0;

    for (int i = 0; i < n; i++) {
        current += garbage[i];

        if (current >= k) {
            bags += current / k;
            current %= k;
        }
    }

    if (current > 0) {
        bags++;
    }

    cout << bags << endl;

    return 0;
}