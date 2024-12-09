#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int left = max(1, i-D);
        int right = min(N, i+D);
        if (left == 1 && right == N) {
            ans++;
        } else if (left == 1 || right == N) {
            ans++;
        } else if (i == 1 || i == N) {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}