#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, X;
    cin >> n >> X;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int animals = 0;
    int food = X;

    for (int i = 0; i < n; i++) {
        if (food >= c[i]) {
            animals++;
            food -= c[i];
        } else {
            break;
        }
    }

    cout << animals << endl;

    return 0;
}