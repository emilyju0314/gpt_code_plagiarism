#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool isSquare(int num) {
    int sq = sqrt(num);
    return sq * sq == num;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = n + 1;
    for(int mask = 1; mask < (1 << n); mask++) {
        int product = 1;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                product *= a[i];
            }
        }
        if(isSquare(product)) {
            result = min(result, __builtin_popcount(mask));
        }
    }

    if(result == n + 1) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}