#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        bool possible = true;
        int max_val = arr[n-1];
        for(int i=n-1; i>=0; i--) {
            if(arr[i] > max_val) {
                possible = false;
                break;
            }
            max_val = arr[i];
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}