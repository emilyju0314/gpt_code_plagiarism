#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string a;
    cin >> a;

    vector<int> f(10);
    for (int i = 1; i <= 9; i++) {
        cin >> f[i];
    }

    bool canReplace = false;
    for (int i = 0; i < n; i++) {
        if (f[a[i] - '0'] > a[i] - '0') {
            canReplace = true;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (canReplace && f[a[i] - '0'] > a[i] - '0') {
            while (i < n && f[a[i] - '0'] >= a[i] - '0') {
                a[i] = f[a[i] - '0'] + '0';
                i++;
            }
            break;
        }
    }

    cout << a << endl;

    return 0;
}