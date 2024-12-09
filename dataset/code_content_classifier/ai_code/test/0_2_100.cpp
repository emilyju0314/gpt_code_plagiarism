#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());

        int max_min = arr[n-1];
        for(int i = n-2; i >= 0; i--) {
            int diff = arr[i+1] - arr[i];
            if(diff < max_min) {
                max_min = diff;
            } else {
                break;
            }
        }
        
        cout << max_min << endl;
    }

    return 0;
}