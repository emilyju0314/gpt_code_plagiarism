#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    map<int, int> freq_a, freq_b;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq_a[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        freq_b[b[i]]++;
    }

    int diff = 0;
    for (int i = 0; i < m; i++) {
        bool possible = true;
        for (auto& [num, freq] : freq_b) {
            int target = (num - i + m) % m;
            if (freq_a[target] != freq) {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            diff = i;
            break;
        }
    }

    cout << diff << endl;

    return 0;
}