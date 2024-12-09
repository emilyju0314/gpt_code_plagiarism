#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> answers(n);
    for (int i = 0; i < n; i++) {
        cin >> answers[i];
    }

    vector<int> points(m);
    for (int i = 0; i < m; i++) {
        cin >> points[i];
    }

    int max_score = 0;
    for (int i = 0; i < m; i++) {
        vector<int> count(5, 0);
        for (int j = 0; j < n; j++) {
            switch (answers[j][i]) {
                case 'A':
                    count[0]++;
                    break;
                case 'B':
                    count[1]++;
                    break;
                case 'C':
                    count[2]++;
                    break;
                case 'D':
                    count[3]++;
                    break;
                case 'E':
                    count[4]++;
                    break;
            }
        }
        max_score += points[i] * (*max_element(count.begin(), count.end()));
    }

    cout << max_score << endl;

    return 0;
}