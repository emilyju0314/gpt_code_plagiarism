#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, d;
        cin >> n >> d;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_map<long long, int> mp;
        int steps = 0;
        while(mp[accumulate(a.begin(), a.end(), 0LL)] == 0) {
            mp[accumulate(a.begin(), a.end(), 0LL)]++;
            vector<int> new_a(n);
            for(int i = 0; i < n; i++) {
                new_a[i] = a[(i + n - d) % n] & a[i];
            }
            a = new_a;
            steps++;
        }

        if(accumulate(a.begin(), a.end(), 0LL) == 0) {
            cout << steps << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}