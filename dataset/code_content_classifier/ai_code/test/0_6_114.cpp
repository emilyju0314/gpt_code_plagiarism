#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        set<int> s;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = a[i];
                int y = a[j];
                if (s.count(x) && s.count(y) && !s.count(x % y) && x != y) {
                    cout << x << " " << y << endl;
                    count++;
                }

                if (count >= n/2) {
                    break;
                }
            }

            if (count >= n/2) {
                break;
            }
        }
    }

    return 0;
}