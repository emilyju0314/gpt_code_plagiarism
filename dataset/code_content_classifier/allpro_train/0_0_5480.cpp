#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n), c(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for(int i = 0; i < m; i++) {
        int op;
        cin >> op;

        if(op == 1) {
            int k, x;
            cin >> k >> x;
            a[k-1] = x;
        } else if(op == 2) {
            int r;
            cin >> r;
            int count = 0;
            for(int i = 0; i < r-2; i++) {
                for(int j = i+1; j < r-1; j++) {
                    for(int k = j+1; k < r; k++) {
                        if(b[a[i]-1]==a[j] && c[a[j]-1]==a[k]) {
                            count++;
                        }
                    }
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}