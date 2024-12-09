#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isBugDetected(int N, int M, vector<pair<int, int>>& rules) {
    unordered_map<int, unordered_map<int, int>> exchange;

    for (int i = 0; i < M; i++) {
        int A = rules[i].first;
        int B = rules[i].second;

        if (exchange[B][A] != 0) {
            if (exchange[A][B] * exchange[B][A] > 1) {
                return true;
            }
            exchange[A][B] = 1;
        } else {
            exchange[A][B]++;
        }
    }

    return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> rules;

    for (int i = 0; i < M; i++) {
        int A, B, x;
        cin >> A >> B >> x;
        rules.push_back(make_pair(A, B));
    }

    if (isBugDetected(N, M, rules)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}