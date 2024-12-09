#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    long long low = 1, high = 1e18;
    while (low < high) {
        long long mid = (low + high) / 2;
        long long time = 0;
        for (int i = 0; i < n; i++) {
            time += max(0LL, piles[i] - (mid - i));
            if (time > mid) {
                break;
            }
        }

        if (time > mid) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << low + n << endl;

    return 0;
}