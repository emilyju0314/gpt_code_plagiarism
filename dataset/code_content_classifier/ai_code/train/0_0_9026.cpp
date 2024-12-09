#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<pair<int, int>> pos;

        int sum = 0;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if(i > 0 && a[i] < a[i-1]) {
                pos.push_back(make_pair(a[i], i));
            }
        }

        if(sum % n != 0) {
            cout << -1 << endl;
            continue;
        }

        int target = sum / n;
        int ops = 0;
        vector<tuple<int,int,int>> operations;

        for(auto p : pos) {
            while(a[p.second] < target) {
                int diff = target - a[p.second];
                int x = min(p.first, diff);
                a[p.second] += x;
                a[p.first] -= x;
                operations.push_back(make_tuple(p.first, p.second, x*p.second));
                ops++;

                if(a[p.first] == target) break;
            }
        }

        if(ops > 3*n) {
            cout << -1 << endl;
        } else {
            cout << ops << endl;
            for(auto op : operations) {
                cout << get<1>(op) << " " << get<2>(op) << " " << get<0>(op) << endl;
            }
        }
    }

    return 0;
}