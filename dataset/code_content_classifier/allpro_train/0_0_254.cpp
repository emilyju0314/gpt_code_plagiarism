#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<long long, long long> count;
    long long result = 0, pref = 0;

    count[pref]++;
    for (int i = 0; i < n; i++) {
        pref ^= a[i];

        for (int j = 0; j < 60; j++) {
            long long target = pref ^ (1LL << j);
            result += count[target];
        }

        count[pref]++;
    }

    cout << result << endl;

    return 0;
}