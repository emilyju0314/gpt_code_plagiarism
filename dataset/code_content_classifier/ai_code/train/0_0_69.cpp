#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first + a.second < b.first + b.second;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> vehicles(N);

    for(int i=0; i<N; i++){
        cin >> vehicles[i].first >> vehicles[i].second;
    }

    sort(vehicles.begin(), vehicles.end(), compare);

    int cumulative_weight = 0;
    int cumulative_marugu = 0;

    for(int i=0; i<N; i++){
        cumulative_weight = max(cumulative_weight, vehicles[i].first) + vehicles[i].second;
        cumulative_marugu = max(cumulative_marugu, cumulative_weight);
    }

    cout << cumulative_weight << " " << cumulative_marugu << endl;

    return 0;
}