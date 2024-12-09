#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    sort(a.begin(), a.end(), greater<int>());

    for (int i = 0; i < a.length(); i++) {
        for (int j = a.length() - 1; j > i; j--) {
            if (a[j] > a[i]) {
                swap(a[i], a[j]);
                if (a.compare(b) <= 0) {
                    break;
                }
                swap(a[i], a[j]);
            }
        }
    }

    cout << a << endl;

    return 0;
}