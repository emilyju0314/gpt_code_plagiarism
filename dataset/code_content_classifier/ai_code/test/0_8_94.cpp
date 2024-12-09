#include <iostream>
#include <vector>

using namespace std;

int min_banknotes(vector<int>& denominations, int s, int k) {
    int num_banknotes = 0;
    int idx = denominations.size() - 1;
    while(s > 0) {
        int count = s / (int)pow(10, denominations[idx]);
        num_banknotes += count;
        s -= count * (int)pow(10, denominations[idx]);
        idx--;
    }
    return num_banknotes;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> denominations(n);
        for(int i = 0; i < n; i++) {
            cin >> denominations[i];
        }

        int ans = -1;
        for(int s = 1; s < 1e9; s++) {
            if(min_banknotes(denominations, s, k) > k) {
                ans = s;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}