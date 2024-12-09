#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    vector<int> mods(P, 0);
    long long ans = 0, ten = 1, sum = 0;
    mods[0] = 1;

    for (int i = N - 1; i >= 0; i--) {
        sum = (sum + (S[i] - '0')*ten) % P;
        ans += mods[sum];
        mods[sum]++;
        ten = (ten * 10) % P;
    }

    cout << ans << endl;

    return 0;
}