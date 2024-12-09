#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    vector<int> shopping_centres(N);
    vector<int> shopping_times(N);

    for(int i = 0; i < N; i++) {
        cin >> shopping_centres[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> shopping_times[i];
    }

    // Calculate the total time required to finish shopping
    long long total_time = 0;
    for(int i = 0; i < N; i++) {
        // Time taken to reach the shopping center
        total_time += 2 * shopping_centres[i];

        // Time taken to shop at the shopping center
        total_time += shopping_times[i];
    }

    // Add time taken to return home
    total_time += L;

    cout << total_time << endl;

    return 0;
}