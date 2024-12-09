#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> heights(n);
        for(int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        int pos = 0;
        while(k > 0 && pos < n-1) {
            if(heights[pos] < heights[pos+1]) {
                heights[pos]++;
                k--;
            } else {
                pos++;
            }
        }

        if(k == 0) {
            cout << pos + 1 << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}