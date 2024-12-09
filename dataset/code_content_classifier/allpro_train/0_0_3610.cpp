#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    int k;
    cin >> n >> k;
    
    vector<int> hitIndicators(k);
    for (int i = 0; i < k; i++) {
        cin >> hitIndicators[i];
    }
    
    long long result = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        int bits = 0, mult = 1;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                bits++;
                mult *= hitIndicators[i];
            }
        }
        if (bits % 2 == 1) {
            result += n / mult;
        } else {
            result -= n / mult;
        }
    }
    
    cout << result << endl;
    
    return 0;
}