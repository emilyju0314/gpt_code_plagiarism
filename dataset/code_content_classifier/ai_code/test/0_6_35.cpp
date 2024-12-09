#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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

    stack<int> st;
    int ans = 0;
    int prod = 1; // current product
    int div = 1; // current division

    for (int l = 0, r = 0; r < n; r++) {
        if (b[r] == '*') {
            prod *= a[r];
            div *= a[r];
        } else {
            prod = div = a[r];
        }

        while (l < r && (prod % div != 0 || (st.size() && st.top() % div != 0))) {
            if (st.size()) {
                prod /= st.top();
                st.pop();
            } else {
                l++;
            }
        }

        if (prod % div == 0) {
            ans += r - l + 1;
        }

        st.push(a[r]);
    }

    cout << ans << endl;

    return 0;
}