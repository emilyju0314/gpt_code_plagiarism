#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, N;
    cin >> a >> b;
    cin >> N;

    vector<pair<int, int>> reservations;
    for (int i = 0; i < N; i++) {
        int s, f;
        cin >> s >> f;
        reservations.push_back(make_pair(s, f));
    }

    for (int i = 0; i < N; i++) {
        if ((a < reservations[i].second && b > reservations[i].first) 
            || (b > reservations[i].first && a < reservations[i].second)) {
            cout << "1";
            return 0;
        }
    }

    cout << "0";

    return 0;
}