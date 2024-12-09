#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MOD 998244353

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    long long ans = 1;
    for(int i=0; i<3*N; i+=3) {
        vector<char> colors = {S[i], S[i+1], S[i+2]};
        sort(colors.begin(), colors.end());
        if(colors[0] == colors[2]) {
            ans = (ans * 3) % MOD;
        } else if(colors[0] == colors[1] || colors[1] == colors[2]) {
            ans = (ans * 2) % MOD;
        }
    }

    cout << ans << endl;
    
    return 0;
}