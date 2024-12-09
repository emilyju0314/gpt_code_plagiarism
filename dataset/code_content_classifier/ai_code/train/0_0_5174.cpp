#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    vector<int> x(N), y(M);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> y[i];
    }

    bool war = true;
    for (int Z = X + 1; Z <= Y; Z++) {
        if (Z > *max_element(x.begin(), x.end()) && Z <= *min_element(y.begin(), y.end())) {
            war = false;
            break;
        }
    }

    if (war) {
        cout << "War" << endl;
    } else {
        cout << "No War" << endl;
    }

    return 0;
}