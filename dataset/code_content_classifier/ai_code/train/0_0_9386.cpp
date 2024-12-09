#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> segments(n);
    
    int totalIntegers = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        totalIntegers += (r - l + 1);
    }
    
    int remainder = totalIntegers % k;
    
    int moves = (remainder == 0) ? 0 : k - remainder;
    
    cout << moves << endl;
    
    return 0;
}