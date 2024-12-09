#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int q;
    cin >> q;
    
    vector<long long> queries(q);
    
    for(int i=0; i<q; i++) {
        cin >> queries[i];
    }
    
    for(int i=0; i<q; i++) {
        long long k = queries[i];
        long long n = sqrt(2 * k);
        
        while(n * (n + 1) / 2 < k) {
            n++;
        }
        
        long long offset = n * (n - 1) / 2;
        long long val = k - offset - 1;
        
        cout << val % n << endl;
    }
    
    return 0;
}