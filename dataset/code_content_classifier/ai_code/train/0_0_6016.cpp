#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    long long steps = abs(b[0]);
    long long max_diff = b[0];
    
    for(int i = 1; i < n; i++) {
        steps += abs(b[i] - b[i-1]);
        max_diff = max(max_diff, (long long)b[i] - b[i-1]);
    }
    
    steps -= max_diff;
    
    cout << steps << endl;
    
    return 0;
}