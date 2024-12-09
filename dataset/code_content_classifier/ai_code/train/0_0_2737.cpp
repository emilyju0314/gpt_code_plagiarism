#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<set<int>> sets(201);

    for (int i = 0; i < n * (n - 1) / 2; i++) {
        int k;
        cin >> k;
        vector<int> numbers(k);
        
        for (int j = 0; j < k; j++) {
            cin >> numbers[j];
            sets[numbers[j]].insert(i);
        }
    }

    vector<set<int>> output(n);

    for (int i = 1; i <= 200; i++) {
        for (int j = i + 1; j <= 200; j++) {
            set<int> intersection;
            set_intersection(sets[i].begin(), sets[i].end(), sets[j].begin(), sets[j].end(), inserter(intersection, intersection.begin()));
            for (int idx : intersection) {
                output[idx].insert(i);
                output[idx].insert(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << output[i].size() << " ";
        for (int num : output[i]) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}