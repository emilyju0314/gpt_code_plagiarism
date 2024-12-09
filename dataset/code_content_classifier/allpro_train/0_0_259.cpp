#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int even = 0, odd = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    if (even == n || odd == n || even % 2 == 0 || odd % 2 == 0) {
        cout << "0" << endl;
    } else {
        cout << "1" << endl;
    }

    return 0;
}