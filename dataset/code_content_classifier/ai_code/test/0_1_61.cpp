#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> problems(n);
        for(int i = 0; i < n; i++) {
            int topic, difficulty;
            cin >> topic >> difficulty;
            problems[i] = make_pair(topic, difficulty);
        }

        sort(problems.begin(), problems.end());

        long long ans = 0;
        for(int i = 0; i < 3; i++) {
            int count = 1;
            while(i+count < n && problems[i].first == problems[i+count].first) {
                count++;
            }
            ans += max(0, count-2);
        }

        sort(problems.begin(), problems.end(), [](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        });

        for(int i = 0; i < 3; i++) {
            int count = 1;
            while(i+count < n && problems[i].second == problems[i+count].second) {
                count++;
            }
            ans += max(0, count-2);
        }

        cout << ans << endl;
    }

    return 0;
}