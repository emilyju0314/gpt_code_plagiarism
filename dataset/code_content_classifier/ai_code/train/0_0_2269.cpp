#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, char>> strings(n+1);
    for(int i = 1; i <= n; i++) {
        int p;
        char c;
        cin >> p >> c;
        strings[i] = make_pair(p, c);
    }

    int k;
    cin >> k;

    vector<int> indices(k);
    for(int i = 0; i < k; i++) {
        cin >> indices[i];
    }

    vector<int> seconds_to_type(n+1, -1);
    seconds_to_type[0] = 0;
    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int i = 1; i <= n; i++) {
            if(strings[i].first == current) {
                int seconds = seconds_to_type[current] + 1;
                if(seconds_to_type[i] == -1 || seconds < seconds_to_type[i]) {
                    seconds_to_type[i] = seconds;
                    q.push(i);
                }
            }
        }
    }

    for(int i = 0; i < k; i++) {
        cout << seconds_to_type[indices[i]] << " ";
    }
    
    return 0;
}