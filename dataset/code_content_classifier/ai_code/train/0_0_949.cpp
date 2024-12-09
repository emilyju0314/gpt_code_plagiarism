#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N, A;
    long long K;
    cin >> N >> A >> K;

    vector<int> SA(N);
    for(int i = 0; i < N; i++) {
        cin >> SA[i];
    }

    string result = "";
    for(int i = 0; i < N; i++) {
        result += 'a' + (SA[i] - 1);
    }

    if(K > 1) {
        if(next_permutation(result.begin(), result.end(), greater<char>())) {
            for(int i = 1; i < K; i++) {
                if(!next_permutation(result.begin(), result.end(), greater<char>())) {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        } else {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    cout << result << endl;

    return 0;
}