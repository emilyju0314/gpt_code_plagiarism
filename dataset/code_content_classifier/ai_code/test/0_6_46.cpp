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

        int k = 0, max_val = a[n-1];
        for(int i = n-1; i >= 0; i--) {
            if(a[i] > max_val) {
                max_val = a[i];
                k++;
            }
        }

        cout << k << endl;
    }

    return 0;
}