#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> mainCourses(k);
    vector<vector<int>> courses(n + 1);

    for (int i = 0; i < k; i++) {
        cin >> mainCourses[i];
    }

    for (int i = 1; i <= n; i++) {
        int numDepends;
        cin >> numDepends;

        for (int j = 0; j < numDepends; j++) {
            int depend;
            cin >> depend;
            courses[i].push_back(depend);
        }
    }

    vector<bool> passed(n + 1, false);
    vector<int> order;

    for (int i = 0; i < k; i++) {
        int currCourse = mainCourses[i];

        if (!passed[currCourse]) {
            queue<int> q;
            q.push(currCourse);

            while (!q.empty()) {
                int course = q.front();
                q.pop();

                if (passed[course]) {
                    continue;
                }

                passed[course] = true;
                order.push_back(course);

                for (int j = 1; j <= n; j++) {
                    if (find(courses[j].begin(), courses[j].end(), course) != courses[j].end()) {
                        q.push(j);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!passed[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << order.size() << endl;
    for (int course : order) {
        cout << course << " ";
    }
    cout << endl;

    return 0;
}