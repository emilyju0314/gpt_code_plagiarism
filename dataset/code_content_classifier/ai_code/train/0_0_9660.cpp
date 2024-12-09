#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long ans = 0;
    for (int l = 0; l < n; l++) {
        int min_val = arr[l];
        for (int s = 1; s < n; s++) {
            if (arr[(l+s)%n] >= min_val) {
                ans++;
                min_val = arr[(l+s)%n];
            } else {
                break;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}