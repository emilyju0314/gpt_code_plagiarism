#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    b[0] = 0;
    int mex = 0;

    for(int i = 1; i < n; i++) {
        if(a[i] > a[i - 1]) {
            mex = a[i - 1];
        } else {
            mex = a[i];
        }
        b[i] = mex;
    }

    // Check if the generated array b meets the conditions
    for(int i = 0; i < n; i++) {
        vector<int> subset(b.begin(), b.begin() + i + 1);
        sort(subset.begin(), subset.end());
        if(subset[i] != a[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Print the array b
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}