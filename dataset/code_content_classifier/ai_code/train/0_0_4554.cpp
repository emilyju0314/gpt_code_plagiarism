#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> l(m);
    for(int i = 0; i < m; i++) {
        cin >> l[i];
    }

    vector<int> a(n, -1);

    for(int i = 0; i < m - 1; i++) {
        int diff = l[i+1] - l[i];
        if(diff <= 0) {
            diff += n;
        }

        if(a[l[i]-1] == -1) {
            a[l[i]-1] = diff;
        } else {
            if(a[l[i]-1] != diff) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == -1) {
            for(int j = 1; j <= n; j++) {
                bool found = false;
                for(int k = 0; k < m - 1; k++) {
                    int next = (i + a[i]) % n;
                    if(next == i) {
                        found = true;
                        break;
                    } else {
                        i = next;
                    }
                }
                if(!found) {
                    a[i] = j;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == -1) {
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}