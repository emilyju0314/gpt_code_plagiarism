#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B, M;
    cin >> A >> B >> M;

    vector<int> a(A), b(B);
    vector<int> x(M), y(M), c(M);

    for (int i = 0; i < A; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < B; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> x[i] >> y[i] >> c[i];
    }

    int min_cost = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());

    for (int i = 0; i < M; i++) {
        int discount = a[x[i] - 1] + b[y[i] - 1] - c[i];
        min_cost = min(min_cost, discount);
    }

    cout << min_cost << endl;

    return 0;
}