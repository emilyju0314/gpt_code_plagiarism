#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int minVal = n, maxVal = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            minVal = min(minVal, i + 1);
            maxVal = max(maxVal, i + 1);
        }
    }
    for(int i = minVal - 1; i < maxVal; i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }

        if(isPossible(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}