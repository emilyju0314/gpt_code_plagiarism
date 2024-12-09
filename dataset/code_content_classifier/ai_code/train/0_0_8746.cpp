#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> scores;
    for (int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        scores.push_back({a + b + c + d, i + 1});
    }

    sort(scores.begin(), scores.end(), compare);

    for (int i = 0; i < n; i++){
        if (scores[i].second == 1){
            cout << i + 1;
            break;
        }
    }

    return 0;
}