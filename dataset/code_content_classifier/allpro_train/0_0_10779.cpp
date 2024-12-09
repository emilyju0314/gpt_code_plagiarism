#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> cows(N);
    for(int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    int pathLength = 0;
    for(int i = 1; i < N; i++) {
        pathLength += max(abs(cows[i].first - cows[i-1].first), abs(cows[i].second - cows[i-1].second));
    }

    // Loop back to the first cow
    pathLength += max(abs(cows[0].first - cows[N-1].first), abs(cows[0].second - cows[N-1].second));

    // Add the path length to return to the starting point for each cow
    pathLength += 2*N;

    cout << pathLength << endl;

    return 0;
}