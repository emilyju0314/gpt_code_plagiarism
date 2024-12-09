#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    unordered_map<int, int> freq;
    vector<long long> prefix_sum(n+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        prefix_sum[i+1] = prefix_sum[i] + arr[i];
    }

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        
        long long power = 0;

        for (auto it = freq.begin(); it != freq.end(); it++) {
            long long count = prefix_sum[r] - prefix_sum[l-1];
            power += it->second * it->second * count;
        }

        cout << power << endl;
    }

    return 0;
}