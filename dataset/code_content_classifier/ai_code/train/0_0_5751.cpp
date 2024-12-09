#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int schedule[101] = {0};
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        for(int j = a; j <= b; j++) {
            schedule[j]++;
        }
    }

    int day_with_issue = -1;
    int num_issues = 0;
    for(int i = 1; i <= n; i++) {
        if(schedule[i] == 0 || schedule[i] > 1) {
            day_with_issue = i;
            num_issues = max(num_issues, schedule[i]-1);
        }
    }

    if(day_with_issue == -1) {
        cout << "OK";
    } else {
        cout << day_with_issue << " " << num_issues;
    }

    return 0;
}