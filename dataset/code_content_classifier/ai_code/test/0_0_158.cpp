#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> x(n);
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }

        vector<vector<int>> s(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char c;
                cin >> c;
                s[i][j] = c - '0';
            }
        }

        vector<int> p(m);
        for(int i = 0; i < m; i++) {
            p[i] = i + 1;
        }

        sort(p.begin(), p.end());

        int max_surprise = -1;
        vector<int> max_permutation(m);

        do {
            int total_surprise = 0;
            for(int i = 0; i < n; i++) {
                int total_points = 0;
                for(int j = 0; j < m; j++) {
                    if(s[i][j] == 1) {
                        total_points += p[j];
                    }
                }
                total_surprise += abs(x[i] - total_points);
            }

            if(total_surprise > max_surprise) {
                max_surprise = total_surprise;
                max_permutation = p;
            }
        } while(next_permutation(p.begin(), p.end()));

        for(int i = 0; i < m; i++) {
            cout << max_permutation[i] << " ";
        }
        cout << endl;
    }

    return 0;
}