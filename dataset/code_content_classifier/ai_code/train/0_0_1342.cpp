#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> levels(n);
    for (int i = 0; i < n; i++) {
        cin >> levels[i];
    }

    double total_time = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int red_count = 0, green_count = 0, blue_count = 0;
            for (int k = i; k < n; k++) {
                if (levels[k][0] == 'R') red_count++;
                if (levels[k][1] == 'G') green_count++;
                if (levels[k][2] == 'B') blue_count++;
            }

            int total_blocks = red_count + green_count + blue_count;
            total_time += total_blocks / 3.0;
        }
    }

    cout << total_time << endl;

    return 0;
}