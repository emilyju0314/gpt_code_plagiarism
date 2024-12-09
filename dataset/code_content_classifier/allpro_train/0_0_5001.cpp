#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    vector<int> b(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    for(int i = 0; i < N; ++i) {
        cin >> b[i];
    }
    
    bool possible = true;
    long long min_cost = 0;
    
    for(int k = 30; k >= 0; --k) {
        vector<int> mod_a(N);
        
        for(int i = 0; i < N; ++i) {
            mod_a[i] = a[i] % (1 << k);
        }
        
        sort(mod_a.begin(), mod_a.end());
        sort(b.begin(), b.end());
        
        if(mod_a != b) {
            int mask = (1 << k) - 1;
            for(int i = 0; i < N; ++i) {
                if((a[i] & mask) != (b[i] & mask)) {
                    possible = false;
                    min_cost += (1LL << k);
                    break;
                }
            }
        }
    }
    
    if(!possible) {
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
    }
    
    return 0;
}