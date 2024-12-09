#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> remaining(n);
    vector<int> volume(n);

    for (int i = 0; i < n; i++) {
        cin >> remaining[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> volume[i];
    }

    int total_soda = 0;
    for (int i = 0; i < n; i++) {
        total_soda += remaining[i];
    }

    int min_bottles = 1;
    int min_time = total_soda;

    for (int i = 0; i < n; i++) {
        int bottles = 1;
        int time = remaining[i];
        for (int j = 0; j < n; j++) {
            if (j != i && volume[j] >= total_soda - remaining[i]) {
                bottles++;
                time += total_soda - remaining[i];
            }
        }
        if (bottles < min_bottles || (bottles == min_bottles && time < min_time)) {
            min_bottles = bottles;
            min_time = time;
        }
    }

    cout << min_bottles << " " << min_time << endl;

    return 0;
}