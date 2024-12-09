#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int c = (k+1) / 2;
    cout << c << endl;

    vector<int> colors;
    for (int i = 1; i <= c; i++) {
        colors.push_back(i);
    }

    for (int i = 0; i < n*(n-1)/2; i++) {
        cout << colors[i % c] << " ";
    }

    return 0;
}