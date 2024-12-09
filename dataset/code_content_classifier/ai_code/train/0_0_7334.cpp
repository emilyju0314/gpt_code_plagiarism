#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long sum = 0;
    for(int K = 1; K <= N; K++) {
        int divisors = 0;
        for(int i = 1; i <= K; i++) {
            if(K % i == 0) {
                divisors++;
            }
        }
        sum += K * divisors;
    }

    cout << sum << endl;

    return 0;
}