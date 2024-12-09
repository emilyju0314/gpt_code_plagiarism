#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    unordered_map<int, int> cnt;
    int maxXor = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cnt[b[i]]++;
        maxXor ^= b[i];
    }

    int minXor = 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        a.push_back(minXor);
        cnt[b[i]]--;
        minXor = cnt[minXor ^ b[i]] > 0 ? minXor ^ b[i] : maxXor ^ b[i];
    }

    if (minXor == maxXor) {
        cout << "Yes" << endl;
        for (int num : a) {
            cout << num << " ";
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}