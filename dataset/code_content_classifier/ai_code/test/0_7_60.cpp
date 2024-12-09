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
        unordered_map<int, int> freq;

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            freq[a[i]]++;
        }

        long double k = (double)sum / n;
        long long count = 0;
        
        for(int i = 0; i < n; i++) {
            long double newK = (sum - a[i]) / (n - 1); // Exclude i-th element from sum
            int req = newK * (n - 2); // Expected sum after deleting 2 elements

            if(freq.find(req) != freq.end()) {
                if((req == a[i] && freq[req] > 1) || (req != a[i] && freq[req] > 0)) {
                    count += freq[req];
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}