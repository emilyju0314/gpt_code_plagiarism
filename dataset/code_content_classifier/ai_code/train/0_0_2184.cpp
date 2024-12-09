#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<long long> a(n);
    long long x = 0;
    for(int i = 0; i < n; i++) {
        a[i] = b[i] + x;
        x = max(x, a[i]);
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}