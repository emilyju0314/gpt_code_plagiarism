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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> possibleK;

        for(int k = 1; k <= n; k++) {
            bool possible = true;

            int x = a[0];
            for(int i = 1; i < n; i++) {
                x = x & a[i];
            }

            if((x & (x - 1)) != 0) {
                possible = false;
            }

            for(int i = 0; i < n; i++) {
                if((a[i] & x) != a[i]) {
                    int countBits = __builtin_popcount(a[i]);
                    if(countBits == 1) {
                        possible = false;
                        break;
                    }
                }
            }

            if(possible) {
                possibleK.push_back(k);
            }
        }

        for(int k : possibleK) {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}