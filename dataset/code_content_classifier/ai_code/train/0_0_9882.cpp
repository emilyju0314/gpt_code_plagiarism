#include <iostream>
#include <vector>

using namespace std;

bool is_lucky(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<pair<int, int>> swaps;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j] && (is_lucky(arr[i]) || is_lucky(arr[j]))) {
                swaps.push_back({i, j});
                swap(arr[i], arr[j]);
            }
        }
    }
    
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1] && (is_lucky(arr[j]) || is_lucky(arr[j+1]))) {
                swaps.push_back({j, j+1});
                swap(arr[j], arr[j+1]);
            }
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << swaps.size() << endl;
    for (auto s : swaps) {
        cout << s.first+1 << " " << s.second+1 << endl;
    }
    
    return 0;
}