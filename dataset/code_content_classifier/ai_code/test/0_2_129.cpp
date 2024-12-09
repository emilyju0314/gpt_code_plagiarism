#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperations(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    if(arr[0] != 1) return -1;

    int ops = 0;
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] == arr[i-1]) return -1;
        while(arr[i] <= arr[i-1]) {
            arr[i] += arr[i-1];
            ops++;
        }
    }

    return ops;
}

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

        cout << minOperations(arr) << endl;
    }

    return 0;
}