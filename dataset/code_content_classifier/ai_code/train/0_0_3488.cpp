#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> paper(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    vector<pair<int, int>> frame1, frame2;

    bool found = false;

    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < m-2; j++) {
            if (paper[i][j] == '#' && paper[i][j+1] == '#' && paper[i][j+2] == '#' &&
                paper[i+1][j] == '#' && paper[i+1][j+2] == '#' &&
                paper[i+2][j] == '#' && paper[i+2][j+1] == '#' && paper[i+2][j+2] == '#') {

                frame1.push_back(make_pair(i+1, j+1));
                frame1.push_back(make_pair(i+3, j+3));

                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        found = false;
        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < m-2; j++) {
                if (paper[i][j] == '.' && paper[i][j+1] == '.' && paper[i][j+2] == '.' &&
                    paper[i+1][j] == '.' && paper[i+1][j+2] == '.' &&
                    paper[i+2][j] == '.' && paper[i+2][j+1] == '.' && paper[i+2][j+2] == '.') {

                    frame2.push_back(make_pair(i+1, j+1));
                    frame2.push_back(make_pair(i+3, j+3));

                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << frame1[0].first << " " << frame1[0].second << " " << frame1[1].first << " " << frame1[1].second << endl;
            cout << frame2[0].first << " " << frame2[0].second << " " << frame2[1].first << " " << frame2[1].second << endl;
        }
    }

    return 0;
}