#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N, M, K;
    cin >> N;

    vector<int> x(N);
    for(int i=0; i<N; i++) {
        cin >> x[i];
    }

    cin >> M >> K;

    vector<int> a(M);
    for(int i=0; i<M; i++) {
        cin >> a[i];
    }

    vector<double> position(N);
    for(int i=0; i<N; i++) {
        position[i] = x[i];
    }

    for(int k=0; k<K; k++) {
        vector<double> next_position(N);
        for(int i=1; i<N-1; i++) {
            double left_jump = (position[i-1] + position[i])/2.0;
            double right_jump = (position[i] + position[i+1])/2.0;
            next_position[i] = (left_jump + right_jump)/2.0;
        }
        for(int i=0; i<N; i++) {
            position[i] = next_position[i];
        }
    }

    for(int i=0; i<N; i++) {
        cout << fixed << setprecision(9) << position[i] << endl;
    }

    return 0;
}