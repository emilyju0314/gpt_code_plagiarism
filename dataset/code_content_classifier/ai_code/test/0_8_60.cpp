#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        long long sum = 0;
        unordered_map<int, int> freq;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            freq[a[i]]++;
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            long long new_sum = sum - a[i];
            int new_n = n - 1;

            if(new_n * a[i] == new_sum) {
                count += freq[a[i]] - 1;
            } else if(freq.find(new_sum - a[i]) != freq.end()) {
                count += freq[new_sum - a[i]];
            }
        }

        cout << count / 2 << endl;
    }

    return 0;
}