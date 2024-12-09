#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> problems(n);
    for (int i = 0; i < n; i++) {
        cin >> problems[i];
    }

    int total_problems = 0;
    for (int i = 0; i < n; i++) {
        total_problems += problems[i];
    }

    int solved_problems = 0;
    int day = 0;
    for (int i = 0; i < n; i++) {
        solved_problems += problems[i];
        if (solved_problems >= (total_problems+1)/2) {
            day = i + 1;
            break;
        }
    }

    cout << day << endl;

    return 0;
}