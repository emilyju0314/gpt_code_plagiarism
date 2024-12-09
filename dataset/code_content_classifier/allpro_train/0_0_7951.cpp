#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);
    vector<int> c;

    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        c.push_back(a[i]);
        c.push_back(b[i]);
    }

    sort(c.rbegin(), c.rend());

    long long total_sleep = 0;
    int wake_ups = 0;
    int early_wake_ups = 0;

    for(int i = 0; i < 2*N; i++) {
        if(i % 2 == 0) {
            total_sleep += c[i];
        } else {
            total_sleep += c[i];
            if(total_sleep >= 10800 && total_sleep <= 32400) {
                wake_ups++;
                if(c[i] >= 10800) {
                    early_wake_ups++;
                }
            }
        }
    }

    cout << early_wake_ups << endl;

    return 0;
}