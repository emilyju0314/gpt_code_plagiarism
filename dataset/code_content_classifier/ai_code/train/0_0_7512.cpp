#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<long long> w(N), d(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> d[i];
    }
    
    long long l = 1, r = 1e18;
    
    while (l < r) {
        long long m = (l + r) / 2;
        long long count = 0;
        
        for (int i = 0; i < N; i++) {
            if (m < w[i]) continue;
            count += (m - w[i]) / d[i] + 1;
        }
        
        if (count < K) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    cout << l << endl;
    
    return 0;
}