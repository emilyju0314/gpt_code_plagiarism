#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, Y0, Y1;
    cin >> N >> M >> Y0 >> Y1;

    vector<int> mice(N);
    vector<int> cheese(M);

    for(int i = 0; i < N; i++) {
        cin >> mice[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> cheese[i];
    }

    int result = 0;
    int j = 0;
    for(int i = 0; i < N; i++) {
        while(j < M - 1 && abs(mice[i] - cheese[j]) >= abs(mice[i] - cheese[j+1])) {
            j++;
        }
        if(abs(mice[i] - cheese[j]) < abs(mice[i] - cheese[j+1])) {
            result++;
        }
    }

    cout << N - result << endl;

    return 0;
}