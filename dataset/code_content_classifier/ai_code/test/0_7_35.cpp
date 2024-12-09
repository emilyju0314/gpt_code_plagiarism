#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<char> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int count = 0;
    vector<double> x(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j > i) {
                if (b[j] == '*') {
                    x[j] = x[j-1] * a[j];
                } else {
                    x[j] = x[j-1] / a[j];
                }
            }

            if (x[j] == (int)x[j]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}