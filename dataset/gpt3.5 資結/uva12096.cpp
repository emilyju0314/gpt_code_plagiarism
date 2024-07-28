#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

map<set<int>, int> setMap;
vector<set<int>> setList;

int setId;

int getSetId(set<int>& s) {
    if (setMap.count(s) == 0) {
        setMap[s] = setId++;
        setList.push_back(s);
    }
    return setMap[s];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        setId = 0;
        setMap.clear();
        setList.clear();

        int N;
        cin >> N;

        stack<int> s;
        while (N--) {
            string op;
            cin >> op;
            if (op == "PUSH") {
                s.push(getSetId(set<int>()));
            }
            else if (op == "DUP") {
                s.push(s.top());
            }
            else {
                set<int> x1 = setList[s.top()];
                s.pop();
                set<int> x2 = setList[s.top()];
                s.pop();

                set<int> result;
                if (op == "UNION") {
                    set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(result, result.begin()));
                }
                else if (op == "INTERSECT") {
                    set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(result, result.begin()));
                }
                else if (op == "ADD") {
                    result = x2;
                    result.insert(getSetId(x1));
                }

                s.push(getSetId(result));
            }

            cout << setList[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }

    return 0;
}