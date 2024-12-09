#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cost = 0;
    for(int i = 0; i < n; i++) {
        int gc = arr[i];
        for(int j = 0; j < n; j++) {
            if(i != j) {
                gc = gcd(gc, arr[j]);
            }
        }
        if(gc == 1) {
            cout << "0" << endl;
            return 0;
        }
    }

    sort(arr.begin(), arr.end());

    int del_cost = x * n;
    int incr_cost = y;
    for(int i = 0; i < n; i++) {
        if(gcd(arr[i]+1, 2) == 1) {
            incr_cost = min(incr_cost, y - x);
        }
    }

    cost = min(del_cost, incr_cost);
    cout << cost << endl;

    return 0;
}