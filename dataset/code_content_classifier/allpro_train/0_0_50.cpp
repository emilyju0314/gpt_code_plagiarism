#include <iostream>
#include <vector>

using namespace std;

bool canConductExperiment(int n, vector<long long>& labSupplies, vector<long long>& requiredAmounts, vector<pair<int, int>>& transformations) {
    for (int i = n - 1; i > 0; i--) {
        if (labSupplies[i] < requiredAmounts[i]) {
            long long shortage = requiredAmounts[i] - labSupplies[i];
            int sourceMaterial = transformations[i - 1].first;
            int transformationRatio = transformations[i - 1].second;
            long long additionalMaterial = transformationRatio * shortage;
            labSupplies[i] += shortage;
            labSupplies[sourceMaterial] -= additionalMaterial;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (labSupplies[i] < requiredAmounts[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<long long> labSupplies(n + 1);
    vector<long long> requiredAmounts(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> labSupplies[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> requiredAmounts[i];
    }

    vector<pair<int, int>> transformations(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x, k;
        cin >> x >> k;
        transformations[i] = {x, k};
    }

    if (canConductExperiment(n, labSupplies, requiredAmounts, transformations)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}