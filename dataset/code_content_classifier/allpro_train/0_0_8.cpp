#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> p(n);
    p[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        p[i] = p[i+1] + 1;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != 0) {
            int idx = i - s[i];
            swap(p[i], p[idx]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}