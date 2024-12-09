#include <iostream>
#include <vector>

using namespace std;

vector<int> findKIntegers(int n, int k) {
    vector<int> result;
    while (n % 2 == 0 && k > 1) {
        result.push_back(2);
        n /= 2;
        k--;
    }
    if (k == 1) {
        result.push_back(n);
    }
    if (result.size() == 1) {
        result.clear();
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> solution = findKIntegers(n, k);

    if (solution.empty()) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < solution.size(); i++) {
            cout << solution[i] << " ";
        }
        cout << endl;
    }

    return 0;
}