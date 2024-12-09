#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> foam(n);
    for (int i = 0; i < n; i++) {
        cin >> foam[i];
    }

    vector<int> shelf;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        auto it = find(shelf.begin(), shelf.end(), x);
        if (it != shelf.end()) {
            shelf.erase(it);
        } else {
            shelf.push_back(x);
        }

        int score = 0;
        for (int j = 0; j < shelf.size(); j++) {
            for (int k = j + 1; k < shelf.size(); k++) {
                if (gcd(foam[shelf[j]-1], foam[shelf[k]-1]) == 1) {
                    score++;
                }
            }
        }
        cout << score << endl;
    }

    return 0;
}