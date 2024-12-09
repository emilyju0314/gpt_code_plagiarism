#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> numerator(n);
    vector<int> denominator(m);

    for (int i = 0; i < n; i++) {
        cin >> numerator[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> denominator[i];
    }

    int num = 1;
    int den = 1;

    for (int i = 0; i < n; i++) {
        num *= numerator[i];
    }

    for (int i = 0; i < m; i++) {
        den *= denominator[i];
    }

    int common_divisor = gcd(num, den);

    num /= common_divisor;
    den /= common_divisor;

    cout << n << " " << m << endl;

    for (int i = 0; i < n; i++) {
        cout << num << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++) {
        cout << den << " ";
    }
    cout << endl;

    return 0;
}