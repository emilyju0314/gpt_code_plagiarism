#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countZeros(long long x) {
    int count = 0;
    while (x % 10 == 0) {
        count++;
        x /= 10;
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    int maxRoundness = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) == k) {
            long long product = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    product *= numbers[i];
                }
            }
            maxRoundness = max(maxRoundness, countZeros(product));
        }
    }
    
    cout << maxRoundness << endl;
    
    return 0;
}