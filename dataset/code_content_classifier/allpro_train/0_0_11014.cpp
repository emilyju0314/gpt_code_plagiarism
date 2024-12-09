#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool is_valid_permutation(vector<int>& a, vector<int>& prefix_sums, int l, int r) {
    int n = a.size();
    for(int i=l; i<=r; i++) {
        if(prefix_sums[a[i]] - prefix_sums[a[i-1]] != 1) {
            return false;
        }
    }
    return true;
}

int solve_permutations(vector<int>& a) {
    int n = a.size();
    vector<int> prefix_sums(n+1, 0);
    for(int i=1; i<=n; i++) {
        prefix_sums[i] = prefix_sums[i-1] + (a[i-1] == i);
    }

    int count = 0;
    vector<pair<int, int>> results;

    for(int i=1; i<n; i++) {
        int l1 = i;
        int l2 = n - i;
        
        if(is_valid_permutation(a, prefix_sums, 0, l1-1) && is_valid_permutation(a, prefix_sums, l1, n-1)) {
            count++;
            results.push_back({l1, l2});
        }
    }

    cout << count << endl;
    for(auto& p : results) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        solve_permutations(a);
    }

    return 0;
}