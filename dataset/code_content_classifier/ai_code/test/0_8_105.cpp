#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        vector<pair<pair<int, int>, int>> dishes(n);
        for (int i = 0; i < n; i++) {
            int a, b, m;
            cin >> a >> b >> m;

            dishes[i] = make_pair(make_pair(a, b), m);
        }

        // Sort dishes by total mass
        sort(dishes.begin(), dishes.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
            return a.first.first + a.first.second < b.first.first + b.first.second;
        });

        int totalVariety = 0;
        vector<pair<int, int>> eatingInstructions(n);
        for (int i = 0; i < n; i++) {
            pair<pair<int, int>, int> currentDish = dishes[i];
            int fishRequired = min(currentDish.second, currentDish.first.first);
            int meatRequired = currentDish.second - fishRequired;

            eatingInstructions[i] = make_pair(fishRequired, meatRequired);
            totalVariety += (fishRequired == 0 || meatRequired == 0);
        }

        cout << totalVariety << endl;
        for (int i = 0; i < n; i++) {
            cout << eatingInstructions[i].first << " " << eatingInstructions[i].second << endl;
        }
    }

    return 0;
}