#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> left(q+1, n);
    vector<int> right(q+1, -1);

    for(int i=0; i<n; i++) {
        cin >> a[i];
        if(a[i] != 0) {
            left[a[i]] = min(left[a[i]], i);
            right[a[i]] = max(right[a[i]], i);
        }
    }

    vector<int> result(n, -1);
    for(int i=1; i<=q; i++) {
        for(int j=left[i]; j<=right[i]; j++) {
            if(result[j] == -1) {
                result[j] = i;
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(a[i] == 0) {
            a[i] = result[i];
        }
    }

    for(int i=1; i<=q; i++) {
        if(left[i] == n) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}