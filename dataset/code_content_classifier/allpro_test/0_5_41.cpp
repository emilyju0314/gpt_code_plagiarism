#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int c = (k + 1) / 2;

    cout << c << endl;
    vector<int> colors;

    for (int i = 1; i <= c; i++) {
        colors.push_back(i);
    }

    int colorIndex = 0;
    for (int i = 1; i <= n-1; i++) {
        for (int j = i+1; j <= n; j++) {
            cout << colors[colorIndex % c] << " ";
            colorIndex++;
        }
    }

    return 0;
}