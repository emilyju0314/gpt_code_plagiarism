#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> instruments;
    for (int i = 0; i < n; i++) {
        int days;
        cin >> days;
        instruments.push_back({days, i+1});
    }

    sort(instruments.begin(), instruments.end());

    int totalDays = 0;
    vector<int> learnedInstruments;
    for (int i = 0; i < n; i++) {
        if (totalDays + instruments[i].first <= k) {
            totalDays += instruments[i].first;
            learnedInstruments.push_back(instruments[i].second);
        } else {
            break;
        }
    }

    cout << learnedInstruments.size() << endl;
    for (int instrument : learnedInstruments) {
        cout << instrument << " ";
    }
    
    return 0;
}