#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> events(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> events[i];
    }

    stack<int> s;
    vector<int> result;

    int j = 0; 
    for (int i = 0; i < 2*n; i++) {
        if (events[i] == '+') {
            s.push(j+1);
        } else {
            int x;
            cin >> x;
            if (s.empty() || s.top() > x) {
                cout << "NO" << endl;
                return 0;
            }
            while (!s.empty() && s.top() <= x) {
                result.push_back(s.top());
                s.pop();
            }
            result.push_back(x);
        }
        j++;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}