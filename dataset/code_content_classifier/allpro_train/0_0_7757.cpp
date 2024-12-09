#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    long long total_inversions = 0;
    double expected_inversions = 0;

    for (int i = 0; i < n; i++) {
        total_inversions += i;
    }

    for (int i = 0; i < n; i++) {
        expected_inversions += 1.0 * i * (n - i - 1) / 2;
    }

    double answer = expected_inversions / total_inversions;
    cout << fixed;
    cout.precision(12);
    cout << answer << endl;

    return 0;
}