#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dpL(n), dpR(n);
    dpL[0] = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i-1]) {
            dpL[i] = dpL[i-1] + 1;
        } else {
            dpL[i] = 1;
        }
    }

    dpR[n-1] = 1;
    for(int i = n-2; i >= 0; i--) {
        if(a[i] < a[i+1]) {
            dpR[i] = dpR[i+1] + 1;
        } else {
            dpR[i] = 1;
        }
    }

    int maxLength = 1, idx = 0;
    for(int i = 0; i < n; i++) {
        if(dpL[i] + dpR[i] - 1 > maxLength) {
            maxLength = dpL[i] + dpR[i] - 1;
            idx = i;
        }
    }

    cout << maxLength << endl;

    string moves = "";
    while(dpL[idx] > 1) {
        moves += "L";
        dpL[idx]--;
        idx--;
    }
    while(dpR[idx] > 1) {
        moves += "R";
        dpR[idx]--;
        idx++;
    }

    cout << moves << endl;

    return 0;
}