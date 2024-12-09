#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> b(n);
        map<int, int> freq_b;
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            freq_b[b[i]]++;
        }

        bool possible = true;
        vector<int> a(n, 0);

        for(int i = 1; i <= n+1; i++) {
            if(possible) {
                if(freq_b[i] > 0) {
                    if(x > 0) {
                        a[i-1] = i;
                        x--;
                    } else {
                        a[i-1] = n+1;
                        y--;
                    }
                    freq_b[i]--;
                } else {
                    if(y > x) {
                        a[i-1] = i;
                        y--;
                    } else {
                        a[i-1] = n+1;
                        y--;
                    }
                }
            } else {
                break;
            }
        }

        if(x == 0 && y == 0) {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}