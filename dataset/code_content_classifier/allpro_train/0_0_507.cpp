#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, L, R;
    cin >> N >> L >> R;

    vector<int> weights(N);
    for(int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    int position = 0;
    for(int i = 0; i < N; i++) {
        int weight = weights[i];
        int max_position = L/2 - (R + weight);
        int min_position = -L/2 + (R + weight);

        if(position < min_position || position > max_position) {
            cout << "No" << endl;
            return 0;
        }

        position += weight;
    }

    cout << "Yes" << endl;

    return 0;
}