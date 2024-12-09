#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int maxTheorems = 0;
    int awakeTheorems = 0;
    for (int i = 0; i < n; i++) {
        if (i < k && t[i] == 0) {
            awakeTheorems += a[i];
        }
        maxTheorems += a[i];
    }

    int start = 0;
    int end = k - 1;
    int currentTheorems = awakeTheorems;
    while (end < n) {
        maxTheorems = max(maxTheorems, currentTheorems);
        currentTheorems -= (t[start] == 0 ? a[start] : 0);
        start++;
        end++;
        currentTheorems += (end < n && t[end] == 0 ? a[end] : 0);
    }

    cout << maxTheorems << endl;

    return 0;
}