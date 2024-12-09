#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<long long, int> count; // to store the count of each prefix XOR value
    count[0] = 1;

    long long xor_value = 0;
    long long ans = 0;

    for(int i = 0; i < n; i++) {
        xor_value ^= a[i];
        ans += count[xor_value];
        count[xor_value]++;
    }

    cout << ans << endl;

    return 0;
}