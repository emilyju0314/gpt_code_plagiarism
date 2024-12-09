#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> episodes(n);
    for(int i = 0; i < n; i++) {
        cin >> episodes[i];
    }
    
    map<int, int> freq;
    long long ans = 0;
    
    for(int i = 1; i <= n; i++) {
        if (freq.count(episodes[i-1] - i)) {
            ans += freq[episodes[i-1] - i];
        }
        freq[episodes[i-1] + i]++;
    }
    
    cout << ans << endl;
    
    return 0;
}