#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> lengths(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    string terrain;
    cin >> terrain;

    long long time = 0;
    int stamina = 0;

    for (int i = 0; i < n; i++) {
        if (terrain[i] == 'G') {
            time += lengths[i] * 5;
            stamina += lengths[i];
        } else if (terrain[i] == 'W') {
            time += lengths[i] * 3;
            stamina += lengths[i];
        } else { // 'L'
            long long fly_time = lengths[i];
            if (fly_time <= stamina) {
                time += fly_time;
                stamina -= fly_time;
            } else {
                long long fly_part = stamina;
                time += fly_part;
                time += (fly_time - fly_part) * 1;
                stamina = 0;
            }
        }
    }

    cout << time << endl;

    return 0;
}