#include <iostream>
#include <vector>
#include <algorithm>

int eversion(vector<int>& a) {
    int n = a.size();
    int k = 0;
    int x = a[n-1];
    vector<int> left;
    vector<int> right;

    for(int i = 0; i < n-1; i++) {
        if(a[i] <= x) {
            left.push_back(a[i]);
        } else {
            right.push_back(a[i]);
        }
    }

    a.clear();
    a.insert(a.end(), left.begin(), left.end());
    a.push_back(x);
    a.insert(a.end(), right.begin(), right.end());
    k++;

    return k;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int k = 0;
        while(true) {
            int num_eversions = eversion(a);
            if(num_eversions == k) {
                break;
            }
            k = num_eversions;
        }

        cout << k << endl;
    }

    return 0;
}