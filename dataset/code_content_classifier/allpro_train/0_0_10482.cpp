#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;

    vector<long long> a(n);
    vector<long long> x(n);
    vector<long long> b(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for(int i = 0; i < n; i++) {
        b[i] = a[i] + t;
    }

    for(int i = 0; i < n; i++) {
        if(b[i] > a[x[i]-1]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}