#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    cin >> t >> n;
    
    for (int i = 0; i < t; i++) {
        long long a, b;
        cin >> a >> b;
        
        long long diff = abs(a - b);
        cout << min(diff, n - diff) << endl;
    }
    
    return 0;
}