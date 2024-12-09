#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> ratios(n+1, 0);
        vector<unordered_map<int, int>> count(n+1);

        int K = 0;
        int D = 0;

        for(int i = 1; i <= n; i++) {
            if(s[i-1] == 'D') {
                D++;
            } else {
                K++;
            }

            int gcd = __gcd(K, D);
            int ratio = (K / gcd) * 1000000 + D / gcd;

            ratios[i] = ratio;
            count[i][ratio]++;
        }

        for(int i = 1; i <= n; i++) {
            if(count[i][ratios[i]] > 1) {
                count[i][ratios[i]]--;
            }

            cout << count[i][ratios[i]] + 1 << " ";
        }

        cout << endl;
    }

    return 0;
}