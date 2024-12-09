#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> dominoes(n);

    for (int i = 0; i < n; i++) {
        cin >> dominoes[i].first >> dominoes[i].second;
    }

    for (int i = 0; i < n; i++) {
        int count = 1; // count of dominoes that will fall
        int x = dominoes[i].first;
        int h = dominoes[i].second;

        for (int j = i + 1; j < n; j++) {
            if (dominoes[j].first > x + h - 1) {
                break;
            }
            count++;
        }

        cout << count << " ";
    }

    return 0;
}