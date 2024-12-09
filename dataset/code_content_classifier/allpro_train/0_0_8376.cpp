#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }

    vector<int> quarrel_count(n, 0);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        quarrel_count[x]++;
        quarrel_count[y]++;
    }

    vector<int> mentors_count(n, 0);
    for (int i = 0; i < n; i++) {
        mentors_count[i] = n - quarrel_count[i] - 1;
    }

    for (int i = 0; i < n; i++) {
        int mentor = 0;
        for (int j = 0; j < n; j++) {
            if (skills[i] < skills[j] && quarrel_count[i]) {
                mentor++;
            }
        }
        cout << mentor << " ";
    }

    return 0;
}