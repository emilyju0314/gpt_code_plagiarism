#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> paints(n);
    for (int i = 0; i < n; i++) {
        cin >> paints[i];
    }

    int squares = paints[0];
    int min_paint = paints[0];

    for (int i = 1; i < n; i++) {
        min_paint = min(min_paint, paints[i]);
        squares += min_paint;
    }

    cout << squares << endl;

    return 0;
}