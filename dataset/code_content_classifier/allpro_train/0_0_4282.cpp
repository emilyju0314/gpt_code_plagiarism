#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Check if tournament configuration is possible
    if (n % 2 == 1 && k > n/2) {
        cout << -1 << endl;
        return 0;
    }

    int numMatches = n * k;
    cout << numMatches << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            int opponent = (i + j) % n;
            if (opponent == 0) opponent = n;
            cout << i + 1 << " " << opponent << endl;
        }
    }

    return 0;
}