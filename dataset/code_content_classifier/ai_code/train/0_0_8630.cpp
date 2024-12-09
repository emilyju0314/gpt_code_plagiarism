#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ages(n);
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }

    vector<int> displeasures(n, -1);

    vector<int> younger_indices;
    younger_indices.push_back(n-1);

    for (int i = n-2; i >= 0; i--) {
        while (!younger_indices.empty() && ages[i] > ages[younger_indices.back()]) {
            displeasures[i] = max(displeasures[i], younger_indices.back() - i - 1);
            younger_indices.pop_back();
        }
        if (!younger_indices.empty()) {
            displeasures[i] = max(displeasures[i], younger_indices.back() - i - 1);
        }
        younger_indices.push_back(i);
    }

    for (const auto& displeasure : displeasures) {
        cout << displeasure << " ";
    }

    return 0;
}