#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, S;
    cin >> n >> S;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int k = 0, T = 0;
    for(int i = 0; i < n; i++) {
        int remaining = S - a[i];
        int possible_k = min(remaining / (i + 1), n - i);
        
        if(possible_k <= 0) {
            break;
        }
        
        int total_cost = a[i] * possible_k + (possible_k * (2 * i + possible_k - 1) / 2);
        
        if(total_cost > T) {
            T = total_cost;
            k = possible_k;
        }
    }
    
    cout << k << " " << T << endl;
    
    return 0;
}