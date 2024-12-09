#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<int, long long> cnt; // to store number of occurrences of each element
        map<pair<int, int>, long long> pairs; // to store number of unordered pairs of indexes for each element
        
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += pairs[{a[i], i}];
            for (auto& p : cnt) {
                int val = p.first;
                pairs[{val, i}] += p.second;
            }
            cnt[a[i]]++;
        }

        cout << sum << endl;
    }

    return 0;
}