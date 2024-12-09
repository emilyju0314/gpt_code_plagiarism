#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> p(n), t(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int limak_points = 0, radewoosh_points = 0;
    int limak_time = 0, radewoosh_time = 0;

    for(int i = 0; i < n; i++) {
        limak_time += t[i];
        limak_points += max(0, p[i] - c * limak_time);

        radewoosh_time += t[n - 1 - i];
        radewoosh_points += max(0, p[n - 1 - i] - c * radewoosh_time);
    }

    if(limak_points > radewoosh_points) {
        cout << "Limak";
    } else if(radewoosh_points > limak_points) {
        cout << "Radewoosh";
    } else {
        cout << "Tie";
    }

    return 0;
}