#include <iostream>

using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int minCost = A*X + B*Y;
    int ABCount = max(X, Y) * 2;

    for (int i = 0; i <= ABCount; i += 2) {
        int cost = i * C + max(0, X - i/2) * A + max(0, Y - i/2) * B;
        minCost = min(minCost, cost);
    }

    cout << minCost << endl;

    return 0;
}