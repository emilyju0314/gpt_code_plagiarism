#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, string>> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i].first >> names[i].second;
    }

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    vector<string> handles(n);
    for (int i = 0; i < n; i++) {
        if (permutation[i] > n) {
            cout << "NO" << endl;
            return 0;
        }
        handles[permutation[i] - 1] = (names[i].first <= names[i].second) ? names[i].first : names[i].second;
    }

    vector<string> sorted_handles = handles;
    sort(sorted_handles.begin(), sorted_handles.end());

    if (handles == sorted_handles) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}