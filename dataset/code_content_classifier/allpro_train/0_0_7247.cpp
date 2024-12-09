#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<string> strings(N);
    vector<long long> costs(N);
    for (int i = 0; i < N; i++) {
        cin >> strings[i] >> costs[i];
    }
    
    int max_len = 0;
    long long total_cost = 0;
    unordered_map<string, long long> dp;
    
    for (int i = 0; i < N; i++) {
        string s = strings[i];
        long long cost = costs[i];
        reverse(s.begin(), s.end());
        
        for (int j = 0; j <= max_len; j++) {
            string new_str = s + strings[j];
            string rev_str = new_str;
            reverse(rev_str.begin(), rev_str.end());
            
            if (new_str == rev_str || new_str.substr(0, new_str.length()-1) == rev_str.substr(1)) {
                long long new_cost = dp[strings[j]] + cost;
                if (dp.find(new_str) == dp.end() || dp[new_str] > new_cost) {
                    dp[new_str] = new_cost;
                    
                    if (new_str == rev_str) {
                        total_cost = (total_cost == 0) ? new_cost : min(total_cost, new_cost);
                    }
                }
            }
        }
        
        dp[s] = cost;
        max_len = max(max_len, (int) s.length());
        
    }
    
    if (total_cost == 0) {
        cout << -1 << endl;
    } else {
        cout << total_cost << endl;
    }
    
    return 0;
}