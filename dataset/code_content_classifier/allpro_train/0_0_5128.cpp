#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> a(6);
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }

    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int min_fret = 1e9;
    int max_fret = 0;
    for (int i = 0; i < n; i++) {
        min_fret = min(min_fret, b[i] - a[0]);
        max_fret = max(max_fret, b[i] - a[5]);
    }

    cout << max_fret - min_fret << endl;

    return 0;
}