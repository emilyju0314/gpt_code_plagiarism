#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> health(N);
    for (int i = 0; i < N; i++) {
        cin >> health[i];
    }

    long long explosions = 0;
    long long total_damage = A - B;

    sort(health.begin(), health.end());

    long long total_health = 0;
    for (int i = 0; i < N; i++) {
        total_health += health[i];
    }

    for(int i = N - 1; i >= 0; i--) {
        if(total_health <= 0) {
            break;
        }

        total_health -= health[i];
        explosions++;

        if(i > 0) {
            long long diff = A * (i) - B * (N - i);
            if(diff >= total_health) {
                explosions++;
                break;
            } else {
                total_health -= diff;
                explosions++;
            }
        } else {
            explosions++;
        }
    }

    cout << explosions << endl;

    return 0;
}