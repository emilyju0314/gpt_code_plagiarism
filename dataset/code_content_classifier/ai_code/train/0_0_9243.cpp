#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> num_ac(N+1, 0);
    vector<int> num_wa(N+1, 0);
    map<int, bool> ac;
    for (int i = 0; i < M; i++) {
        int p;
        string S;
        cin >> p >> S;
        if (S == "AC") {
            if (!ac[p]) {
                num_ac[p]++;
                num_wa[p] = -1; // to avoid adding to penalties
                ac[p] = true;
            }
        } else {
            if (num_wa[p] != -1) {
                num_wa[p]++;
            }
        }
    }

    int correct_answers = 0;
    int penalties = 0;
    for (int i = 1; i <= N; i++) {
        if (num_ac[i] > 0) {
            correct_answers++;
            penalties += num_wa[i];
        }
    }

    cout << correct_answers << " " << penalties << endl;

    return 0;
}