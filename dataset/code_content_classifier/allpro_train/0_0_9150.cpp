#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> volumes(N);
    vector<int> temperatures(N);

    for (int i = 0; i < N; i++) {
        cin >> volumes[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> temperatures[i];
    }

    int max_volume = 0;
    vector<int> melted_volume(N);

    for (int i = 0; i < N; i++) {
        max_volume = max(max_volume - temperatures[i], volumes[i]);
        melted_volume[i] = volumes[i] - max_volume;
    }

    for (int i = 0; i < N; i++) {
        cout << melted_volume[i] << " ";
    }

    return 0;
}