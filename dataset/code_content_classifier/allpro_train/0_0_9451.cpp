#include <iostream>
#include <vector>

using namespace std;

int findExpansionCoefficient(vector<int>& arr) {
    int maxK = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i+1; j < arr.size(); j++) {
            maxK = max(maxK, (j-i) == 0 ? 0 : (arr[j] - arr[i]) / (j-i));
        }
    }
    return maxK;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int expansionCoefficient = findExpansionCoefficient(arr);
    cout << expansionCoefficient << endl;

    return 0;
}