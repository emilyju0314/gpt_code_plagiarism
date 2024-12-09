#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int MAX_X = 8192;
    vector<bool> possible(MAX_X, false);

    possible[0] = true;
    for (int i = 0; i < n; i++) {
        for (int x = MAX_X - 1; x >= 0; x--) {
            if (possible[x]) {
                possible[x ^ a[i]] = true;
            }
        }
    }

    vector<int> result;
    for (int x = 0; x < MAX_X; x++) {
        if (possible[x]) {
            result.push_back(x);
        }
    }

    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}