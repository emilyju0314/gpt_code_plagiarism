#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(2*n);
    for(int i = 0; i < 2*n; i++) {
        cin >> p[i];
    }

    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < 2*n; i++) {
        if(p[i] != i+1) {
            if(i % 2 == 0) {
                cnt1++;
            } else {
                cnt2++;
            }
        }
    }

    if(cnt1 % 2 != 0 || cnt2 % 2 != 0) {
        cout << -1 << endl;
    } else {
        cout << min(cnt1, cnt2) / 2 << endl;
    }

    return 0;
}