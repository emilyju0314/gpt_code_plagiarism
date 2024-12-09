#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h, k;
    cin >> n >> h >> k;

    vector<int> potatoes(n);
    for(int i = 0; i < n; i++) {
        cin >> potatoes[i];
    }

    long long time = 0;
    long long curr_height = 0;

    for(int i = 0; i < n; i++) {
        while(curr_height + potatoes[i] > h) {
            time++;
            curr_height = max(0LL, curr_height - k);
        }

        curr_height += potatoes[i];
        time++;
    }

    time += (curr_height + k - 1) / k; // Add the time to smash the remaining potatoes

    cout << time << endl;

    return 0;
}