#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> beauty_values(n);
    for (int i = 0; i < n; i++) {
        cin >> beauty_values[i];
    }

    vector<int> capital_cities(k);
    for (int i = 0; i < k; i++) {
        cin >> capital_cities[i];
    }

    long long total_price = 0;
    for (int i = 0; i < n; i++) {
        total_price += beauty_values[i] * beauty_values[(i + 1) % n];
    }

    cout << total_price << endl;

    return 0;
}