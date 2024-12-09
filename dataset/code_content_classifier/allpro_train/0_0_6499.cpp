#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> chocolates(n);
    for(int i = 0; i < n; i++) {
        cin >> chocolates[i];
    }

    long long ans = 0;
    int prev = 0;
    
    sort(chocolates.begin(), chocolates.end());
    
    for(int i = 0; i < n; i++) {
        if(chocolates[i] <= prev) {
            ans += chocolates[i];
            prev = chocolates[i];
        } else {
            ans += prev;
            prev++;
        }
    }

    cout << ans << endl;

    return 0;
}