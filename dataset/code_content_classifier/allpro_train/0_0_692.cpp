#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> monomials;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        monomials.push_back(make_pair(a, b));
    }

    bool canBornaWin = true;

    sort(monomials.begin(), monomials.end());

    // Check if Borna can win by checking if the polynomial is already bounded from below
    int minB = monomials[0].second; // Initialize minB with the lowest power of y
    for (int i = 1; i < N; i++) {
        if (monomials[i].second < minB) {
            canBornaWin = false;
            break;
        }
        minB = min(minB, monomials[i].second);
    }

    if (canBornaWin) {
        cout << "Borna" << endl;
    } else {
        cout << "Ani" << endl;
    }

    return 0;
}