#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Problem {
    int a, t, index;
};

bool compare(Problem p1, Problem p2) {
    return p1.t < p2.t;
}

int main() {
    int n, T;
    cin >> n >> T;

    vector<Problem> problems(n);

    for(int i = 0; i < n; i++) {
        cin >> problems[i].a >> problems[i].t;
        problems[i].index = i + 1;
    }

    sort(problems.begin(), problems.end(), compare);

    vector<int> dp(T+1, 0);
    vector<vector<int>> chosen(T+1);

    for(int i = 0; i < n; i++) {
        for(int j = T - problems[i].t; j >= 0; j--) {
            if(dp[j] + 1 > dp[j + problems[i].t] && problems[i].a >= chosen[j].size()) {
                dp[j + problems[i].t] = dp[j] + 1;
                chosen[j + problems[i].t] = chosen[j];
                chosen[j + problems[i].t].push_back(problems[i].index);
            }
        }
    }

    int maxScore = *max_element(dp.begin(), dp.end());
    cout << maxScore << endl;
    cout << chosen[T].size() << endl;
    for(int i = 0; i < chosen[T].size(); i++) {
        cout << chosen[T][i] << " ";
    }

    return 0;
}