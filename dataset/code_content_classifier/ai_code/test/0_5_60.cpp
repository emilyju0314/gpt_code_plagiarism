#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        long long sum = 0;
        map<long long, int> freq;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            freq[a[i]]++;
        }

        long double k = (long double) sum / n;

        long long count = 0;

        for(int i = 0; i < n; i++) {
            freq[a[i]]--;
            long long new_sum = sum - a[i];
            int new_n = n - 1;
            long double new_k = (long double) new_sum / new_n;
            if(new_k == k) {
                count += freq[a[i]];
            }
            freq[a[i]]++;
        }

        cout << count << endl;
    }

    return 0;
}