#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    vector<int> freq(n + 1);
    map<vector<int>, int> prefixCount;

    vector<int> prefix(n + 1);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ (1 << (a[i] - 1));
    }

    for (int i = 0; i < n + 1; i++) {
        vector<int> c;
        for (int j = 0; j < n; j++) {
            int val = prefix[j] ^ prefix[i];
            c.push_back(freq[val]);
        }
        
        ans += prefixCount[c];
        
        for (int j = 0; j < n; j++) {
            int val = prefix[j] ^ prefix[i];
            freq[val]++;
        }
        prefixCount[c]++;
    }

    cout << ans << endl;

    return 0;
}