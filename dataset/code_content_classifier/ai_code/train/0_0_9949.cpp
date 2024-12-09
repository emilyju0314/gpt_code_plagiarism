#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    vector<int> icicles(N);
    for(int i=0; i<N; i++) {
        cin >> icicles[i];
    }

    int time = 0;
    while(true) {
        bool allBroken = true;
        for(int i=0; i<N; i++) {
            if(i == 0) {
                if(icicles[i] > icicles[i+1]) {
                    icicles[i]++;
                    allBroken = false;
                }
            } else if(i == N-1) {
                if(icicles[i] > icicles[i-1]) {
                    icicles[i]++;
                    allBroken = false;
                }
            } else {
                if(icicles[i] > icicles[i-1] && icicles[i] > icicles[i+1]) {
                    icicles[i]++;
                    allBroken = false;
                }
            }
        }
        if(allBroken) {
            break;
        }
        time++;
    }

    cout << time * L << endl;

    return 0;
}