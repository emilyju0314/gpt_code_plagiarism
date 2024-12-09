#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        cout << "0 1\n";
        cout << "0\n1\n";
    } else {
        cout << n << endl;
        vector<int> first_poly(n+1, 0);
        first_poly[n] = 1; // leading coefficient is 1
        first_poly[0] = -1; // constant term is -1
        for (int coeff : first_poly) {
            cout << coeff << " ";
        }
        cout << endl;

        cout << n-1 << endl;
        vector<int> second_poly(n, 0);
        second_poly[0] = 1; // leading coefficient is 1
        for (int coeff : second_poly) {
            cout << coeff << " ";
        }
        cout << endl;
    }

    return 0;
}