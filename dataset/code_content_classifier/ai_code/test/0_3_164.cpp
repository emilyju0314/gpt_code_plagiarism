#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> l, r;
vector<char> label;
vector<string> result;
int k;

void dfs(int node) {
    if(node == 0) return;

    string left = "";
    string right = "";

    dfs(l[node]);
    dfs(r[node]);

    if(l[node] != 0) left = result[l[node]];
    if(r[node] != 0) right = result[r[node]];

    result[node] = left + label[node] + right;

    priority_queue<char, vector<char>, greater<char>> duplicates;

    if(l[node] != 0) {
        for(char c : result[l[node]]) {
            if(duplicates.size() < k) duplicates.push(c);
            else if(duplicates.top() < c) {
                duplicates.pop();
                duplicates.push(c);
            }
        }
    }

    if(r[node] != 0) {
        for(char c : result[r[node]]) {
            if(duplicates.size() < k) duplicates.push(c);
            else if(duplicates.top() < c) {
                duplicates.pop();
                duplicates.push(c);
            }
        }
    }

    while(!duplicates.empty()) {
        string updated = "";
        for(char c : result[node]) {
            if(c == duplicates.top()) {
                updated += c;
                updated += c;
            } else {
                updated += c;
            }
        }
        result[node] = updated;
        duplicates.pop();
    }
}

int main() {
    int n;
    cin >> n >> k;

    l.resize(n+1);
    r.resize(n+1);
    label.resize(n+1);
    result.resize(n+1);

    string initialLabel;
    cin >> initialLabel;

    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        label[i] = initialLabel[i-1];
    }

    dfs(1);

    cout << result[1] << endl;

    return 0;
}