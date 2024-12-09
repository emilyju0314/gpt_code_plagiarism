#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arthur(a);
    vector<int> alexander(b);

    for (int i = 0; i < a; i++) {
        cin >> arthur[i];
    }

    for (int i = 0; i < b; i++) {
        cin >> alexander[i];
    }

    vector<int> result(n, 0);

    for (int i = 0; i < a; i++) {
        result[arthur[i] - 1] = 1;
    }

    for (int i = 0; i < b; i++) {
        result[alexander[i] - 1] = 2;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}