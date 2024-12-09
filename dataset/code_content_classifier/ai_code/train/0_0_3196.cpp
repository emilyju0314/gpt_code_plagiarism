#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K, T, U, V, L;
    cin >> N >> K >> T >> U >> V >> L;
    
    vector<int> carrots(N);
    for (int i = 0; i < N; i++) {
        cin >> carrots[i];
    }
    
    double time = 0.0;
    double speed = U;
    double distance = 0;
    
    for (int i = 0; i < N; i++) {
        double dt = (carrots[i] - distance) / speed;
        time += dt;
        distance = carrots[i];
        
        if (i < N - 1 && carrots[i + 1] - distance >= K) {
            double accTime = (carrots[i + 1] - distance - K) / V;
            time += accTime;
            distance = carrots[i + 1];
            speed = V;
        } else {
            speed = U;
        }
    }
    
    double dt = (L - distance) / speed;
    time += dt;
    
    cout << fixed;
    cout.precision(9);
    cout << time << endl;
    
    return 0;
}