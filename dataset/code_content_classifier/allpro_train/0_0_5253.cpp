#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> volumes(N);
    vector<int> temperatures(N);

    for(int i = 0; i < N; i++) {
        cin >> volumes[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> temperatures[i];
    }

    int current_volume = 0;
    for(int i = 0; i < N; i++) {
        current_volume = max(0, current_volume - temperatures[i]);
        cout << volumes[i] + current_volume << " ";
        current_volume = max(current_volume, volumes[i]);
    }

    return 0;
}