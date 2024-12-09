#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> L(N);

    for(int i = 0; i < N; i++) {
        cin >> L[i];
    }

    int totalTime = 0;
    int remainingCustomers = N;

    while(remainingCustomers > 0) {
        int minTime = 600;
        int minIndex = -1;

        for(int i = 0; i < N; i++) {
            if(L[i] > 0 && L[i] < minTime) {
                minTime = L[i];
                minIndex = i;
            }
        }

        totalTime += minTime * (N - remainingCustomers + 1);
        L[minIndex] = 0;
        remainingCustomers--;
        for(int i = (minIndex + 1) % N; remainingCustomers > 0; i = (i + 1) % N) {
            if(L[i] > 0) {
                L[i] -= minTime;
                if(L[i] == 0) {
                    remainingCustomers--;
                }
            }
        }
    }

    cout << totalTime << endl;

    return 0;
}