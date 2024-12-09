#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    int N = S.size();
    vector<int> cnt(2019, 0);
    cnt[0] = 1;
    
    int num = 0;
    long long ans = 0;

    for (int i = N - 1; i >= 0; i--) {
        int d = S[i] - '0';
        
        num = (num + d * cnt[1]) % 2019;
        ans += cnt[num];

        for (int j = 0; j < 2019; j++) {
            cnt[j] = cnt[j] + (j == num ? 1 : 0);
        }
    }

    cout << ans << endl;

    return 0;
}