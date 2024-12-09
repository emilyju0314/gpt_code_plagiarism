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

    cout << "1 1" << endl;
    cout << -a[0] << endl;

    cout << "2 4" << endl;
    cout << a[1] << " " << -a[1] << " " << -a[1] << endl;

    cout << "3 4" << endl;
    cout << a[3] << " " << -a[3] << endl;

    return 0;
}