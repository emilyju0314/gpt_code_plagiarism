#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        vector<int> permutation(n);
        vector<int> colors(n);

        for(int i = 0; i < n; i++) {
            cin >> permutation[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> colors[i];
        }

        vector<int> positions(n+1, -1);
        map<pair<int, int>, int> counts;
        int answer = n;

        for(int i = 0; i < n; i++) {
            int index = i;
            int color = colors[i];

            vector<int> cycle;
            while(positions[index] == -1) {
                cycle.push_back(index);
                positions[index] = cycle.size();
                index = permutation[index] - 1;
            }

            if(colors[cycle.back()] == color) {
                counts[{color, cycle.size()}]++;
                answer = min(answer, cycle.size() - counts[{color, cycle.size()}] + 1);
            }
        }

        cout << answer << endl;
    }

    return 0;
}