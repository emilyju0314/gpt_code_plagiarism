#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    long long K, P;
    cin >> K >> P;

    int N;
    cin >> N;

    vector<int> s(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    int M;
    cin >> M;

    unordered_map<int, int> values;
    for (int i = 0; i < M; i++) {
        int j, v;
        cin >> j >> v;
        values[j] = v;
    }

    long long result = 0;
    for (int i = N; i <= K; i++) {
        if (values.count(i) > 0) {
            s.push_back(values[i]);
        } else {
            int newValue = (s[i-1] * P + s[i-2] * P) % P;
            s.push_back(newValue);
        }
    }

    cout << s[K] << endl;

    return 0;
}