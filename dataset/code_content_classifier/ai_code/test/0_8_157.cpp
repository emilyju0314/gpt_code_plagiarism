#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    int count_one = 0;
    vector<int> zero_count;
    
    int zeros = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == '0') {
            zeros++;
        } else {
            count_one++;
            zero_count.push_back(zeros);
            zeros = 0;
        }
    }
    zero_count.push_back(zeros);
    
    int total_strings = 0;
    for(int i = 0; i < zero_count.size(); i++) {
        if (zero_count[i] >= k) {
            int zeros_left = zero_count[i] - k;
            total_strings = (total_strings + ((1LL << zeros_left) - 1 + MOD) % MOD) % MOD; // calculating 2 to the power of zeros_left - 1
        }
    }
    
    if (k == 0) {
        total_strings = 1;
    } else if (count_one == 1) {
        total_strings = 1;
    }
    
    cout << total_strings << endl;
    
    return 0;
}