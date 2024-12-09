#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergesort_calls(int n, int k) {
    if (k < n - 1) {
        cout << -1 << endl;
        return;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    // Shuffle the array to meet the required number of mergesort calls
    reverse(a.begin(), a.begin() + (k - n + 1));

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;

    mergesort_calls(n, k);

    return 0;
}