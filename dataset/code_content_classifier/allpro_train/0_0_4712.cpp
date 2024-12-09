#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(vector<int>& bugs, vector<pair<int,int>>& students, int s, int days) {
    long long totalPasses = 0;
    for(int i=0; i<days; i++) {
        totalPasses += students[i].second;
    }
    return totalPasses <= s;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<int> bugs(m);
    for(int i=0; i<m; i++) {
        cin >> bugs[i];
    }

    vector<pair<int,int>> students(n);
    for(int i=0; i<n; i++) {
        cin >> students[i].first;
    }
    for(int i=0; i<n; i++) {
        cin >> students[i].second;
    }

    sort(bugs.begin(), bugs.end());
    sort(students.begin(), students.end());

    int low = 0, high = min(m, n), ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(isValid(bugs, students, s, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if(ans == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for(int i=0; i<m; i++) {
            cout << students[ans-1].first << " ";
        }
        cout << endl;
    }

    return 0;
}