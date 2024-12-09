#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> problems(N);
    for(int i = 0; i < N; i++) {
        cin >> problems[i].first >> problems[i].second;
    }

    sort(problems.begin(), problems.end());

    long long max_joyfulness = 0;
    long long max_joyfulness_left = 0;

    for(int i = 0; i < N; i++) {
        long long joy_left = problems[i].second - problems[0].first + 1;
        long long joy_right = problems[N-1].second - problems[i+1].first + 1;
        
        max_joyfulness = max(max_joyfulness, joy_left + max_joyfulness_left);
        max_joyfulness = max(max_joyfulness, joy_right);

        max_joyfulness_left = max(max_joyfulness_left, joy_left);
    }

    cout << max_joyfulness << endl;

    return 0;
}