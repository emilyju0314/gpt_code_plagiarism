#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int countSimpleSegments(int n, vector<int>& a, vector<char>& b) {
    int count = 0;
    vector<int> product(n+1, 1);
    stack<int> st;

    for (int i = 1; i <= n; i++) {
        product[i] = product[i-1] * a[i-1];
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == '/') {
            st.push(i);
        } else {
            while (!st.empty()) {
                int j = st.top();
                if (product[i+1] % product[j] == 0) {
                    count += 1;
                } else {
                    break;
                }
                st.pop();
            }
        }
    }

    while (!st.empty()) {
        int j = st.top();
        if (product[n] % product[j] == 0) {
            count += 1;
        }
        st.pop();
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<char> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int result = countSimpleSegments(n, a, b);
    cout << result << endl;

    return 0;
}