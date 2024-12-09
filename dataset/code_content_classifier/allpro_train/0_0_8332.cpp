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

        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int cur = 1;
        for(int i = 0; i < n; i++) {
            if(p[i] == cur) {
                cur++;
            }
        }

        if(cur == n + 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}