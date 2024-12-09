#include <iostream>

using namespace std;

long long int minCost(long long int n, long long int a, long long int b) {
    long long int cost = (n/2) * b + (n%2) * a;
    return min(cost, n*a);
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        long long int n, a, b;
        cin >> n >> a >> b;
        cout << minCost(n, a, b) << endl;
    }

    return 0;
}