#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long p, f, cnt_s, cnt_w, s, w;
        cin >> p >> f >> cnt_s >> cnt_w >> s >> w;

        if(s > w) {
            swap(s, w);
            swap(cnt_s, cnt_w);
        }

        long long maxWeapons = 0;
        for(int i = 0; i <= min(cnt_s, p / s); i++) {
            long long remainingSwords = min(cnt_s - i, f / s);
            long long a = i + remainingSwords;
            long long b = min(cnt_w, (p - i * s) / w);
            long long remainingAxes = min(cnt_w - b, (f - remainingSwords * s) / w);
            maxWeapons = max(maxWeapons, a + b);
        }

        cout << maxWeapons << endl;
    }

    return 0;
}