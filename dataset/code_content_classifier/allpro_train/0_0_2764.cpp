#include <iostream>
#include <cmath>

using namespace std;

double calculateProb(int K, double R, double L, double P, double E, double T) {
    double T_prime, prob;

    for (int i = 0; i < K; i++) {
        double H = (R + L) / 2;
        if (rand() / (double) RAND_MAX < P) {
            if (H >= T) {
                L = H;
            } else {
                R = H;
            }
        }
    }

    T_prime = (R + L) / 2;
    prob = 1 - abs(T_prime - T) / E;
    return prob;
}

int main() {
    int K;
    double R, L, P, E, T, prob;

    cin >> K >> R >> L >> P >> E >> T;

    prob = calculateProb(K, R, L, P, E, T);
    
    cout << fixed;
    cout.precision(6);
    cout << prob << endl;

    return 0;
}