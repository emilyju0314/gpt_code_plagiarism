#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> problems(N);
    for(int i = 0; i < N; i++) {
        cin >> problems[i];
    }

    int contests = 0;
    vector<bool> used(N, false);

    for(int i = 0; i < N; i++) {
        if(problems[i] <= A) {
            for(int j = i + 1; j < N; j++) {
                if(A < problems[j] && problems[j] <= B && !used[j]) {
                    for(int k = j + 1; k < N; k++) {
                        if(problems[k] > B && !used[k]) {
                            contests++;
                            used[i] = used[j] = used[k] = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << contests << endl;

    return 0;
}