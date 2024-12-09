#include <iostream>
#include <vector>

using namespace std;

bool isPermutationPossible(int n, vector<int>& a, string& colors) {
    vector<int> freq(n+1, 0);
    for (int i = 0; i < n; i++) {
        if (colors[i] == 'R') {
            freq[a[i]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            return false;
        }
    }

    int maxVal = *max_element(a.begin(), a.end());
    int minVal = *min_element(a.begin(), a.end());

    if (maxVal - minVal >= n) {
        return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        string colors;
        cin >> colors;

        if (isPermutationPossible(n, a, colors)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}