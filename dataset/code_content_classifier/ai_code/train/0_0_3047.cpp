#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(vector<int>& a, vector<int>& b) {
    if(a.size() % 2 != 0 && a != b) {
        return false;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }

        if(isValid(a, b)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}