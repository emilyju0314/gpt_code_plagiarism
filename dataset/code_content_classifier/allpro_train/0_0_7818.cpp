#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> potions(n);
    for(int i = 0; i < n; i++) {
        cin >> potions[i];
    }
    
    long long total = 0;
    long long ans = 0;
    
    for(int i = 0; i < n; i++) {
        total += potions[i];
        if (total < 0) {
            total = 0;
        } else {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}