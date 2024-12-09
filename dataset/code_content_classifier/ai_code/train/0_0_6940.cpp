#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int count_permutations(int n, const vector<string>& relations) {
    int ans = 0;
    for (int mask = 0; mask < (1 << (n-1)); ++mask) {
        bool possible = true;
        vector<int> perm(n);
        for (int i = 0; i < n; ++i) {
            perm[i] = i;
        }
        
        do {
            string bin_str = "";
            for (int i = 0; i < n-1; ++i) {
                bin_str += ((mask >> i) & 1) + '0';
            }
            
            bool valid = true;
            for (int i = 0; i < n-1; ++i) {
                if (bin_str[i] == '1') {
                    if (relations[perm[i]][perm[i+1]] == '0') {
                        valid = false;
                        break;
                    }
                } else {
                    if (relations[perm[i]][perm[i+1]] == '1') {
                        valid = false;
                        break;
                    }
                }
            }
            
            if (valid) {
                ++ans;
            }
        } while (next_permutation(perm.begin(), perm.end()));
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> relations(n);
    for (int i = 0; i < n; ++i) {
        cin >> relations[i];
    }
    
    map<int, int> count_map;
    for (int mask = 0; mask < (1 << (n-1)); ++mask) {
        count_map[mask] = count_permutations(n, relations);
    }
    
    for (int mask = 0; mask < (1 << (n-1)); ++mask) {
        cout << count_map[mask] << " ";
    }
    
    return 0;
}