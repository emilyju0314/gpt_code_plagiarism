#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, x;
    cin >> N >> x;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (x >= a[i]) {
            x -= a[i];
            ans++;
        } else {
            break;
        }
    }

    if (x > 0 && ans == N) {
        ans--;
    }

    cout << ans << endl;

    return 0;
}