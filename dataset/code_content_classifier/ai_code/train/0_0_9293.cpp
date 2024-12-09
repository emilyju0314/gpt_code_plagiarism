#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> colliders(n + 1, false); // Initially all colliders are deactivated
    vector<int> prime(n + 1, 0); // Stores the smallest prime factor for each number

    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) {
            for (int j = i; j <= n; j += i) {
                prime[j] = i;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        char type;
        int collider;
        cin >> type >> collider;

        if (type == '+') {
            if (colliders[collider]) {
                cout << "Already on" << endl;
            } else {
                bool conflict = false;
                for (int j = 1; j*j <= collider; j++) {
                    if (colliders[j] && gcd(j, collider) != 1) {
                        conflict = true;
                        cout << "Conflict with " << j << endl;
                        break;
                    }
                }
                if (!conflict) {
                    colliders[collider] = true;
                    cout << "Success" << endl;
                }
            }
        } else {
            if (!colliders[collider]) {
                cout << "Already off" << endl;
            } else {
                colliders[collider] = false;
                cout << "Success" << endl;
            }
        }
    }

    return 0;
}