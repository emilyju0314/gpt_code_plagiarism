#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> ans(N, 0);
    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            int dist = min(j - i, min(abs(X - i) + abs(Y - j) + 1, abs(Y - i) + abs(X - j) + 1));
            ans[dist]++;
        }
    }

    for(int k = 1; k < N; k++) {
        cout << ans[k] << endl;
    }

    return 0;
}