#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int choose(int n, int k) {
    if(k == 0 || k == n)
        return 1;
    return (choose(n-1, k-1) + choose(n-1, k)) % MOD;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> followers(n);
        for(int i = 0; i < n; i++) {
            cin >> followers[i];
        }
        
        sort(followers.begin(), followers.end(), greater<int>());
        
        int max_followers = followers[k-1];
        int cnt = count(followers.begin(), followers.end(), max_followers);
        
        int total_followers = 0;
        for(int i = 0; i < n; i++) {
            if(followers[i] == max_followers) {
                total_followers++;
            }
        }
        
        cout << choose(total_followers, cnt) << endl;
    }
    
    return 0;
}