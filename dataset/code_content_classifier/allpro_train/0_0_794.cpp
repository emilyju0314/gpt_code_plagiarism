#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = 0;
    for(int i = 0; i < 30; i++) {
        int cnt1 = 0, cnt0 = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] & (1 << i)) {
                cnt1++;
            } else {
                cnt0++;
            }
        }
        result |= ((1 << i) * (n - 1 - cnt1) * cnt1);
    }

    cout << result << endl;

    return 0;
}