#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> s;
    long long points = 0;

    for(int i = 0; i < n; i++) {
        while(!s.empty() && arr[i] > s.top()) {
            int top = s.top();
            s.pop();

            if(!s.empty()) {
                points += min(arr[i], s.top());
            }
        }

        if(!s.empty()) {
            points += min(arr[i], s.top());
        }

        s.push(arr[i]);
    }

    cout << points << endl;

    return 0;
}