#include <iostream>
#include <vector>

using namespace std;

struct Employee {
    int number;
    int level;
    vector<int> children;
};

vector<Employee> employees;

void calculateLevels(int employeeIndex, int level) {
    employees[employeeIndex].level = level;
    for (int child : employees[employeeIndex].children) {
        calculateLevels(child, level + 1);
    }
}

pair<int, int> findBestEmployeeToRemove(int employeeIndex, int minLevel) {
    int bestEmployee = -1;
    int bestLevel = minLevel;
    
    for (int child : employees[employeeIndex].children) {
        pair<int, int> result = findBestEmployeeToRemove(child, max(minLevel, employees[child].level));
        if (result.second > bestLevel) {
            bestEmployee = result.first;
            bestLevel = result.second;
        }
    }
    
    if (bestEmployee == -1) {
        return make_pair(employeeIndex, minLevel - 1);
    }
    return make_pair(bestEmployee, bestLevel);
}

int main() {
    int n, q;
    cin >> n >> q;

    employees.resize(n + 1);
    employees[1].number = 1;
    
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        employees[i].number = i;
        employees[boss].children.push_back(i);
    }

    calculateLevels(1, 0);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        pair<int, int> result = findBestEmployeeToRemove(l, 0);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}