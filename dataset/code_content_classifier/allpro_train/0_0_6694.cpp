#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> percentages(n);
    for (int i = 0; i < n; i++) {
        cin >> percentages[i];
    }

    int total_percentage = 0;
    for (int i = 0; i < n; i++) {
        total_percentage += percentages[i];
    }

    double result = (double) total_percentage / n;
    cout << fixed;
    cout.precision(12);
    cout << result << endl;

    return 0;
}