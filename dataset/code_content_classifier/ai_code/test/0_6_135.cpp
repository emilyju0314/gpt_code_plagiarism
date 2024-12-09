#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int score = 0;
        int idx = k;
        
        for(int i = n-1; i >= 0; i--) {
            if(idx == 0) {
                score += a[i];
            } else {
                idx--;
            }
        }

        cout << score << endl;
    }

    return 0;
}