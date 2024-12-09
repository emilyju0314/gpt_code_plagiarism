#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int c = 1; // minimum number of colors needed
    vector<int> colors;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            colors.push_back(c);
            if (colors.size() >= 2 && colors[colors.size() - 1] == colors[colors.size() - 2]) {
                c++;
            }
        }
    }

    cout << c << endl;
    for (int i = 0; i < colors.size(); i++) {
        cout << colors[i] << " ";
    }
    cout << endl;

    return 0;
}