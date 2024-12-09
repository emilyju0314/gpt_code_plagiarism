#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, x;
    cin >> N >> x;

    vector<long long> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for(int i = 1; i < N; i++) {
        long long total = a[i] + a[i-1];
        if(total > x) {
            long long diff = total - x;
            ans += diff;
            if(a[i] >= diff) {
                a[i] -= diff;
            } else {
                a[i-1] -= (diff - a[i]);
                a[i] = 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}