#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> vacancies(n);
    vector<int> candidates(n);

    for (int i = 0; i < n; i++) {
        cin >> vacancies[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    sort(vacancies.begin(), vacancies.end());
    sort(candidates.begin(), candidates.end());

    int min_distance = 0;
    vector<int> distribution(n);

    for (int i = 0; i < n; i++) {
        min_distance += abs(vacancies[i] - candidates[i]);
        distribution[i] = i+1;
    }

    cout << min_distance << endl;

    for (int i = 0; i < n; i++) {
        cout << distribution[i] << " ";
    }

    return 0;
}