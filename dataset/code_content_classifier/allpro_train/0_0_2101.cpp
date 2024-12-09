#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortByColumn(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    return a.second.second < b.second.second;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> sportsmen;

    for (int i = 0; i < m; i++) {
        int ri, ci;
        cin >> ri >> ci;
        sportsmen.push_back({i+1, {ri, ci}});
    }

    sort(sportsmen.begin(), sportsmen.end(), sortByColumn);

    vector<int> chosenSportsmen;
    pair<int, int> currentCell = {-1, -1};

    for (int i = 0; i < m; i++) {
        if (sportsmen[i].second.first > currentCell.first && sportsmen[i].second.second >= currentCell.second) {
            chosenSportsmen.push_back(sportsmen[i].first);
            currentCell = sportsmen[i].second;
        }
    }

    cout << chosenSportsmen.size() << endl;
    for (int sportsman : chosenSportsmen) {
        cout << sportsman << " ";
    }

    return 0;
}