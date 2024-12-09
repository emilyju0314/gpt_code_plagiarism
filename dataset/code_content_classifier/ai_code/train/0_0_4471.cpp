#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    vector<int> cnt(n+1, 0);
    vector<int> pos;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            pos.push_back(i);
        }
    }
    
    int changes = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[arr[i]] > 1 || arr[i] > n) {
            cnt[arr[i]]--;
            arr[i] = pos[changes];
            cnt[pos[changes]]++;
            changes++;
        }
    }
    
    cout << changes << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}