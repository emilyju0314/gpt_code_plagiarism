#include <bits/stdc++.h>
using namespace std;

bool check(int S) {
    for(int x = 1; x * x <= S; ++x) {
        if((S - x) % (2 * x + 1) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int N; cin >> N;
    int ans = 0;
    while(N--) {
        int S; cin >> S;
        ans += !check(S);
    }
    cout << ans << endl;
}

