#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countNearlyFullSubsequences(vector<int>& arr, int n) {
    unordered_map<long long, int> freq;
    long long sum = 0;
    long long result = 0;

    for(int i=0; i<(1 << n); i++) {
        sum = 0;
        for(int j=0; j<n; j++) {
            if((i & (1 << j)) != 0) {
                sum += arr[j];
            }
        }

        if(freq.count(sum-1)) {
            result += freq[sum-1];
        }
        freq[sum]++;
    }

    return result;
}

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

        cout << countNearlyFullSubsequences(arr, n) << endl;
    }

    return 0;
}