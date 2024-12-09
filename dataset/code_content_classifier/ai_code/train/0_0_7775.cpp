#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> integers(N);
    
    for (int i = 0; i < N; i++) {
        cin >> integers[i].first >> integers[i].second;
    }
    
    sort(integers.begin(), integers.end(), greater<pair<int, int>>());
    
    long long ans = 0;
    
    for (int i = 0; i < N; i++) {
        if ((K | integers[i].first) <= K) {
            ans += integers[i].second;
            K |= integers[i].first;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}