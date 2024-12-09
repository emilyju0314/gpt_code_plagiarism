#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> schedule(n, 0);
    vector<pair<int, int>> exams;
    
    for (int i = 0; i < m; i++) {
        int s, d, c;
        cin >> s >> d >> c;
        exams.push_back({s, d});
        
        int remaining_days = d - s;
        while (c > 0 && remaining_days > 0) {
            for (int j = s; j < d; j++) {
                if (schedule[j] == 0) {
                    schedule[j] = i + 1;
                    c--;
                    remaining_days--;
                    if (c == 0) break;
                }
            }
            s++;
        }
        
        if (c > 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (schedule[i] == 0) {
            bool found_exam = false;
            for (int j = 0; j < m; j++) {
                if (i >= exams[j].first && i < exams[j].second) {
                    schedule[i] = m + 1;
                    found_exam = true;
                    break;
                }
            }
            if (!found_exam) {
                schedule[i] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << schedule[i] << " ";
    }
    cout << endl;

    return 0;
}