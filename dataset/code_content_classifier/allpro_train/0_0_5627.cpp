#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = make_pair(a, b);
    }

    sort(arr.begin(), arr.end());

    cout << arr[n - k].second << endl;

    return 0;
}