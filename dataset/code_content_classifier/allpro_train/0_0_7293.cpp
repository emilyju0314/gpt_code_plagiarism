#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        int prefixSum = 0;
        bool possible = true;
        for(int i = 0; i < n; i++) {
            if(prefixSum > i) {
                possible = false;
                break;
            }
            prefixSum += a[i];
            sum -= a[i];
        }

        if(sum != 0) {
            possible = false;
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}