#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int prev_power = 0;
        int seconds = 0;

        for(int i = 0; i < n; i++) {
            if(a[i] < prev_power) {
                int diff = prev_power - a[i];
                int add_power = 0;

                while((1 << add_power) < diff) {
                    add_power++;
                }

                a[i] += diff;
                prev_power = a[i];
                seconds = max(seconds, add_power);
            } else {
                prev_power = a[i];
            }
        }

        cout << seconds << endl;
    }

    return 0;
}