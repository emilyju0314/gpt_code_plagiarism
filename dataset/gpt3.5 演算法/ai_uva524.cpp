#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ans;
vector<bool> visited;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void backtrack(int idx) {
    if (idx == n) {
        if (isPrime(ans[0] + ans[n - 1])) {
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << " ";
                cout << ans[i];
            }
            cout << endl;
        }
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (!visited[i] && isPrime(i + ans[idx - 1])) {
            visited[i] = true;
            ans[idx] = i;
            backtrack(idx + 1);
            visited[i] = false;
        }
    }
}

int main() {
    int caseNum = 0;
    while (cin >> n) {
        caseNum++;
        if (caseNum > 1) cout << endl;
        ans.clear();
        ans.resize(n);
        visited.resize(n + 1, false);
        ans[0] = 1;
        visited[1] = true;

        cout << "Case " << caseNum << ":" << endl;
        
        backtrack(1);
    }

    return 0;
}
