#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> M(N);
    vector<int> R(N);

    for(int i = 0; i < N; i++) {
        cin >> M[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> R[i];
    }

    int total_days = 0;
    int washing_days = 0;

    for(int day = 0; day <= 1000000; day++) {
        bool wash = true;
        for(int i = 0; i < N; i++) {
            if(day % M[i] != R[i]) {
                wash = false;
                break;
            }
        }

        if(wash) {
            washing_days++;
        }
        total_days++;
    }

    double percentage = (double) washing_days / total_days;
    cout << fixed;
    cout.precision(6);
    cout << percentage << endl;

    return 0;
}