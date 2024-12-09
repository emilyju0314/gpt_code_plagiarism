#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> operations;
        int count = 0;

        while(true) {
            bool changed = false;
            for(int i = 0; i < n-1; i++) {
                if(a[i] >= a[i+1]) {
                    a[i+1] += a[i];
                    operations.push_back({i+1, i+2});
                    for(int j = i; j < n-1; j++) {
                        a[j] = a[j+1];
                    }
                    n--;
                    changed = true;
                    break;
                }
            }
            if(!changed) break;
        }

        cout << operations.size() << endl;
        for(auto op : operations) {
            cout << op.first << " " << op.second << endl;
        }
    }

    return 0;
}