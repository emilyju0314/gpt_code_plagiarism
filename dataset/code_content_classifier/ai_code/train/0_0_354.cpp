#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        vector<int> missingIdx;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == -1) {
                missingIdx.push_back(i);
            }
        }

        int max_diff = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] != -1 && a[i-1] != -1) {
                max_diff = max(max_diff, abs(a[i] - a[i-1]));
            }
        }

        int k;
        if(missingIdx.size() == 1) {
            a[missingIdx[0]] = max_diff;
        } else {
            int l = missingIdx[0];
            int r = missingIdx[1];
            int window = r - l;
            int k1 = max_diff / window;
            int k2 = max_diff % window;

            for(int i = l; i <= r; i++) {
                a[i] = k1;
            }
            a[missingIdx[0]] -= k2;
        }

        cout << max_diff << " ";
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}