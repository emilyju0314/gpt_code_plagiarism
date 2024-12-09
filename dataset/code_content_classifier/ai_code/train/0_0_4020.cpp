#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> jumps(m);
    for (int i = 0; i < m; i++) {
        cin >> jumps[i];
    }

    vector<int> mosquitoes(k);
    for (int i = 0; i < k; i++) {
        cin >> mosquitoes[i];
    }

    sort(jumps.begin(), jumps.end());

    int min_mosquitoes = INT_MAX;
    vector<int> frogs;
    for (int i = 0; i < m; i++) {
        int smashed_mosquitoes = 0;
        for (int j = 0; j < k; j++) {
            if (mosquitoes[j] % jumps[i] == 0) {
                smashed_mosquitoes++;
            }
        }

        if (smashed_mosquitoes < min_mosquitoes) {
            min_mosquitoes = smashed_mosquitoes;
            frogs.clear();
            frogs.push_back(i + 1);
        }
        else if (smashed_mosquitoes == min_mosquitoes) {
            frogs.push_back(i + 1);
        }
    }

    cout << min_mosquitoes << endl;
    for (int frog : frogs) {
        cout << frog << " ";
    }
    cout << endl;

    return 0;
}