#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sizes(n);
    for (int i = 0; i < n; i++) {
        cin >> sizes[i];
    }

    sort(sizes.begin(), sizes.end());

    for (int i = 0; i < n - 1; i++) {
        if (sizes[i] * 2 > sizes[i + 1]) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}