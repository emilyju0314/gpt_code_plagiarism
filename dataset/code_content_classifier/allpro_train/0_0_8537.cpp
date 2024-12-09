#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> strengths(n);
    for (int i = 0; i < n; i++) {
        cin >> strengths[i];
    }

    sort(strengths.begin(), strengths.end());

    int numSupported = 0;
    for (int i = 0; i < n; i++) {
        if ((i == 0 || strengths[i] > strengths[0]) && (i == n - 1 || strengths[i] < strengths[n - 1])) {
            numSupported++;
        }
    }

    cout << numSupported << endl;

    return 0;
}