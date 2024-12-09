#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int unique_elements = 1;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i-1]) {
                unique_elements++;
            }
        }

        if(unique_elements > 1 || (count(arr.begin(), arr.end(), k) > 0)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}