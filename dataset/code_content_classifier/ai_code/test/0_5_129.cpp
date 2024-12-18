#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

        sort(a.begin(), a.end());
        
        int minOperations = 0;
        bool possible = true;

        for(int i = 0; i < n; i++) {
            if(a[i] > i + 1) {
                possible = false;
            }
            minOperations += (i + 1 - a[i]);
        }

        if(possible) {
            cout << minOperations << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}