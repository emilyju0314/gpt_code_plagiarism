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

        sort(arr.begin(), arr.end()); // Sort the array in ascending order

        int mid = n / 2;
        if(n % 2 == 0) {
            mid--;
        }

        vector<int> result;

        // Alternate placing elements from the beginning and end of the sorted array
        for(int i = 0; i <= mid; i++) {
            result.push_back(arr[n - 1 - i]);
            if(i != mid) {
                result.push_back(arr[i]);
            }
        }

        for(int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}