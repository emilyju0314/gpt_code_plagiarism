#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int count = 0;
    int min_val = N;
    for(int i = 0; i < N; i++) {
        if(P[i] < min_val) {
            min_val = P[i];
            count++;
        }
    }

    cout << N - count << endl;

    return 0;
}