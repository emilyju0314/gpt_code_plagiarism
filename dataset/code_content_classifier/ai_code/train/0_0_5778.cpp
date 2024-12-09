#include <iostream>

using namespace std;

int main() {
    int N, H, W;
    cin >> N >> H >> W;

    int ans = (N - H + 1) * (N - W + 1);
    cout << ans << endl;

    return 0;
}