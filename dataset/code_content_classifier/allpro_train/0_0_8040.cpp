#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> microorganisms;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        microorganisms.push_back({a, b});
    }

    sort(microorganisms.begin(), microorganisms.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    });

    int max_alive = 0;
    int intake = 0;

    for(int i = 0; i < N; i++) {
        intake += microorganisms[i].first;
        if(intake <= microorganisms[i].second) {
            max_alive = i + 1;
        } else {
            break;
        }
    }

    cout << max_alive << endl;

    return 0;
}