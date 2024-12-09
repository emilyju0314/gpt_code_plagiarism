#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> events(n);
    for(int i = 0; i < n; i++) {
        cin >> events[i];
    }

    stack<int> st;
    vector<int> days;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(events[i] > 0) {
            st.push(events[i]);
            count++;
        } else {
            if(st.empty() || st.top() != -events[i]) {
                cout << "-1" << endl;
                return 0;
            }

            count++;
            st.pop();

            if(st.empty()) {
                days.push_back(count);
                count = 0;
            }
        }
    }

    if(!st.empty()) {
        cout << "-1" << endl;
        return 0;
    }

    cout << days.size() << endl;
    for(int d: days) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}