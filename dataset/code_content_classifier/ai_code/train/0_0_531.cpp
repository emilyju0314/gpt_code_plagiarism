#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    long long max_score = 0;
    for (int i = 0; i < n; i++) {
        long long total_score = 0;
        for (int j = 0; j < n; j++) {
            if (j >= i && j <= i+1) continue; // Bob removes one card
            total_score += cards[j];
        }
        max_score = max(max_score, total_score);
    }

    cout << max_score << endl;

    return 0;
}