#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    
    int oven1_time = (n + k - 1) / k * t;
    
    int oven2_time = max(d, (n + k - 1) / k * t - d + (n + 2*k - 1) / (2 * k) * t);
    
    if(oven2_time < oven1_time) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}