#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> bacteria(n);
    for (int i = 0; i < n; i++) {
        cin >> bacteria[i];
    }

    sort(bacteria.begin(), bacteria.end());

    int result = n;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && bacteria[j] - bacteria[i] <= k) {
            result--;
            j++;
        }
    }

    cout << result << endl;

    return 0;
}