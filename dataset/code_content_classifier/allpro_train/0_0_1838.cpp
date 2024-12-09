#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countTuples(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> count;
    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                res += count[arr[j]];
            }
        }
        count[arr[i]]++;
    }

    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << countTuples(arr) << endl;
    }

    return 0;
}