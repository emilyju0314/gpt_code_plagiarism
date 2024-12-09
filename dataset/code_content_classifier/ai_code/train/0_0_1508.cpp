#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int min_modular = arr[n-1] - arr[0];
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            min_modular = min(min_modular, arr[j] - arr[i]);
        }
    }

    cout << min_modular << endl;

    return 0;
}