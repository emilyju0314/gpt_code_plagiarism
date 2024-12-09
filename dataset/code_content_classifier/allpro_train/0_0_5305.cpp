#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> salaries(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> salaries[i][j];
        }
    }

    vector<int> employee_salaries;
    vector<pair<int, int>> supervisor_relation;

    // Assign salaries to employees
    for (int i = 0; i < n; i++) {
        employee_salaries.push_back(salaries[i][0]);
    }

    // Find the head of the company
    int head_salary = *max_element(employee_salaries.begin(), employee_salaries.end());
    int head_employee = distance(employee_salaries.begin(), max_element(employee_salaries.begin(), employee_salaries.end()));

    // Assign supervisors to employees
    for (int i = 0; i < n; i++) {
        if (salaries[i][0] == head_salary) {
            supervisor_relation.push_back({i+1, head_employee+1});
        }
    }

    // Output the results
    cout << n + 1 << endl;
    for (int salary : employee_salaries) {
        cout << salary << " ";
    }
    cout << endl;
    cout << n+1 << endl;
    for (pair<int, int> relation : supervisor_relation) {
        cout << relation.first << " " << relation.second << endl;
    }

    return 0;
}