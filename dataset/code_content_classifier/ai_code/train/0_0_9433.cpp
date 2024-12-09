#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> f(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    sort(f.begin(), f.end(), greater<int>());

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int index = 0;
        while (p[index] >= f[i]) {
            index++;
        }
        a[i] = p[index];
        p.erase(p.begin() + index);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}