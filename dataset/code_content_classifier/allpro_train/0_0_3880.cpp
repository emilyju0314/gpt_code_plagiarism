#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> facts(N);
    for (int i = 0; i < N; i++) {
        cin >> facts[i].first >> facts[i].second;
    }

    sort(facts.begin(), facts.end());

    int maxPlayers = facts[0].first + facts[0].second;

    for (int i = 1; i < N; i++) {
        maxPlayers = max(maxPlayers + facts[i].second, facts[i].first + facts[i].second);
    }

    cout << maxPlayers << endl;

    return 0;
}