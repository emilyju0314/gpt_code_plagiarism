#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, B;
    cin >> n >> B;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    int evenCount = 0, oddCount = 0, cuts = 0;
    for (int i = 0; i < n - 1; i++) {
        if (sequence[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }

        if (evenCount == oddCount) {
            cuts += abs(sequence[i] - sequence[i + 1]);
        }
    }

    cout << cuts / 2 << endl;

    return 0;
}