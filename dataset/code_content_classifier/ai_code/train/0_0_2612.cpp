#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        stack<int> st;
        vector<int> freq(n + 1, 0);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int cur = a[i];

            while (!st.empty() && st.top() != cur) {
                st.pop();
            }

            if (!st.empty() && st.top() == cur) {
                st.pop();
            }

            ans += i + 1 - freq[cur];
            freq[cur] = i + 1;
            st.push(cur);
        }

        cout << ans << "\n";
    }

    return 0;
}