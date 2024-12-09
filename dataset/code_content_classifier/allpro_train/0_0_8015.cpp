#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long r;
    cin >> n >> r;

    vector<int> l(n);
    vector<int> t(n);

    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<long long> moments;
    long long total_time = 0;
    long long drinks_used = 0;

    for (int i = 0; i < n; i++) {
        // Calculate the time taken to run across the bridge at normal speed
        total_time += l[i] * 2;

        // Check if Polycarp can run across the bridge within the allowed time
        if (total_time > t[i]) {
            // Calculate the amount of time Polycarp needs to save
            long long time_needed = total_time - t[i];

            if (drinks_used == 100000) {
                cout << "-1" << endl;
                return 0;
            }

            // Calculate the number of drinks needed to save the required time
            long long drinks = time_needed / r;
            if (time_needed % r != 0) {
                drinks++;
            }

            // Update the total time and add the moments to the output
            drinks_used += drinks;
            for (int j = 0; j < drinks; j++) {
                moments.push_back(total_time - r * (j + 1));
            }

            // Reset the total time to its original value
            total_time -= drinks * r;
        }
    }

    cout << drinks_used << endl;
    for (int i = 0; i < moments.size(); i++) {
        cout << moments[i] << " ";
    }

    return 0;
}