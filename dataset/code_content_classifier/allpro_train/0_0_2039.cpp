#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

#define MOD 1000000007

using namespace std;

int power(int a, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) {
        res = (res * 2) % MOD;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    unordered_map<int, int> count;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        for(int j = 2; j * j <= arr[i]; j++) {
            while(arr[i] % j == 0) {
                count[j]++;
                arr[i] /= j;
            }
        }
        if(arr[i] > 1) {
            count[arr[i]]++;
        }
    }

    long long total_ops = 0;
    for(auto it = count.begin(); it != count.end(); it++) {
        total_ops = (total_ops + (power(2, it->second) - 1 + MOD) % MOD) % MOD;
    }

    cout << total_ops << endl;

    return 0;
}