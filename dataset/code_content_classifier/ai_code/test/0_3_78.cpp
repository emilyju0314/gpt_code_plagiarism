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
        vector<int> bits(31, 0);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; j < 31; j++) {
                if((a[i] & (1 << j)) != 0) {
                    bits[j]++;
                }
            }
        }

        bool possible = true;
        for(int i = 0; i < n; i++) {
            bool found = false;
            for(int j = 0; j < 31; j++) {
                if((a[i] & (1 << j)) != 0 && bits[j] == 1) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                possible = false;
                break;
            }
        }

        if(possible) {
            for(int i = 1; i <= n; i++) {
                if(n % i == 0) {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}