#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to calculate the greatest common divisor of two numbers
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

    unordered_set<int> shelf;
    int score = 0;

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;

        if (shelf.count(x)) {
            shelf.erase(x);
        } else {
            for (int glass : shelf) {
                score += (gcd(foam[x - 1], foam[glass - 1]) == 1);
            }
            shelf.insert(x);
        }

        cout << score << endl;
    }

    return 0;
}