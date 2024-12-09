#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<int> dishes;
    priority_queue<int> students;

    for (int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        dishes.push(cost);
    }

    for (int i = 0; i < m; i++) {
        int money;
        cin >> money;
        students.push(money);
    }

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int i, x;
            cin >> i >> x;
            vector<int> temp;
            while (!dishes.empty()) {
                int t = dishes.top();
                dishes.pop();
                if (t == x) {
                    temp.push_back(t);
                    break;
                } else {
                    temp.push_back(t);
                }
            }
            for (int j = 0; j < temp.size(); j++) {
                dishes.push(temp[j]);
            }
        } else {
            int i, x;
            cin >> i >> x;
            vector<int> temp;
            while (!students.empty()) {
                int t = students.top();
                students.pop();
                if (t == x) {
                    temp.push_back(t);
                    break;
                } else {
                    temp.push_back(t);
                }
            }
            for (int j = 0; j < temp.size(); j++) {
                students.push(temp[j]);
            }
        }

        if (dishes.empty() || students.empty()) {
            cout << "-1" << endl;
        } else {
            while (!dishes.empty() && !students.empty() && dishes.top() <= students.top()) {
                dishes.pop();
            }
            if (dishes.empty()) {
                cout << "-1" << endl;
            } else {
                cout << dishes.top() << endl;
            }
        }
    }

    return 0;
}