#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> triples(n-2, vector<int>(3));
    vector<int> p(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n-2; i++) {
        cin >> triples[i][0] >> triples[i][1] >> triples[i][2];
        for (int j = 0; j < 3; j++) {
            freq[triples[i][j]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 1) {
            p[0] = i;
            break;
        }
    }

    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < 3; j++) {
            if (triples[i][j] == p[0] && freq[triples[i][(j+1)%3]] == 2 && freq[triples[i][(j+2)%3]] == 2) {
                p[1] = triples[i][(j+1)%3];
                p[2] = triples[i][(j+2)%3];
                break;
            }
        }
    }

    for (int i = 1; i < n-1; i++) {
        for (int j = 0; j < n-2; j++) {
            if (triples[j][0] == p[i] && triples[j][1] == p[i+1]) {
                p[i+2] = triples[j][2];
                break;
            }
            if (triples[j][1] == p[i] && triples[j][0] == p[i+1]) {
                p[i+2] = triples[j][2];
                break;
            }
            if (triples[j][1] == p[i] && triples[j][2] == p[i+1]) {
                p[i+2] = triples[j][0];
                break;
            }
            if (triples[j][2] == p[i] && triples[j][1] == p[i+1]) {
                p[i+2] = triples[j][0];
                break;
            }
            if (triples[j][0] == p[i] && triples[j][2] == p[i+1]) {
                p[i+2] = triples[j][1];
                break;
            }
            if (triples[j][2] == p[i] && triples[j][0] == p[i+1]) {
                p[i+2] = triples[j][1];
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}