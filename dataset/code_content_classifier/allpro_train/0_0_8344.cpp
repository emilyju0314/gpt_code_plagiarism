#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;

        freq.clear();
        for(int j = l-1; j < r; j++) {
            freq[arr[j]]++;
        }

        int count = 0;
        for(auto& p : freq) {
            if(p.first == p.second) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}