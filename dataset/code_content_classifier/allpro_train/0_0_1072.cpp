#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> tour1(n);
    vector<int> tour2(n);

    for(int i = 0; i < n; i++) {
        cin >> tour1[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> tour2[i];
    }

    sort(tour1.begin(), tour1.end());
    sort(tour2.begin(), tour2.end(), greater<int>());

    int best_place = 1, worst_place = n;

    for(int i = 0; i < n; i++) {
        if(tour1[i] + tour2[i] < x) {
            best_place = max(best_place, i + 2);
        }
        if(tour1[i] < x && tour2[i] < x) {
            worst_place = min(worst_place, i + 1);
        }
    }

    cout << best_place << " " << worst_place << endl;

    return 0;
}