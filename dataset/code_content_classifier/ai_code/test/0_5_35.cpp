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

    for (int l = 0; l < n; l++) {
        int product = 1;
        int division = 1;

        for (int r = l; r < n; r++) {
            if (b[r] == '*') {
                product *= a[r];
            } else {
                division *= a[r];
            }

            if (product == division) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}