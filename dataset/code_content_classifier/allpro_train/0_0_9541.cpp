#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        vector<int> sticks(4*n);
        for(int i = 0; i < 4*n; i++) {
            cin >> sticks[i];
        }

        sort(sticks.begin(), sticks.end());

        int area = sticks[0] * sticks[4*n-1];
        bool possible = true;

        for(int i = 0; i < 2*n; i += 2) {
            if(sticks[i] != sticks[i+1] || sticks[4*n-1-i] != sticks[4*n-1-i-1] || sticks[i] * sticks[4*n-1-i] != area) {
                possible = false;
                break;
            }
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}