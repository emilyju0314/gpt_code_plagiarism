#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> left_child;
vector<int> right_child;
vector<int> allowed_duplications;
vector<string> labels;
vector<string> smallest_string;

void dfs(int node) {
    if (node == 0) {
        smallest_string[node] = "";
        return;
    }

    dfs(left_child[node]);
    dfs(right_child[node]);

    int left_dup = allowed_duplications[left_child[node]] + (labels[node].front() == labels[left_child[node]].front());
    int right_dup = allowed_duplications[right_child[node]] + (labels[node].front() == labels[right_child[node]].front());

    if (left_dup <= allowed_duplications[node] && smallest_string[left_child[node]].front() != 'a') {
        smallest_string[node] = smallest_string[left_child[node]] + labels[node].front() + smallest_string[right_child[node]];
    } else if (right_dup <= allowed_duplications[node] && smallest_string[right_child[node]].front() != 'a') {
        smallest_string[node] = smallest_string[left_child[node]] + labels[node].front() + smallest_string[right_child[node]];
    } else {
        smallest_string[node] = smallest_string[left_child[node]] + smallest_string[right_child[node]];
    }
    
    allowed_duplications[node] = min(allowed_duplications[node], left_dup);
    allowed_duplications[node] = min(allowed_duplications[node], right_dup);
}

int main() {
    int n, k;
    cin >> n >> k;

    left_child.resize(n + 1);
    right_child.resize(n + 1);
    allowed_duplications.resize(n + 1, k);
    labels.resize(n + 1);
    smallest_string.resize(n + 1);

    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        labels[i] = s.substr(i - 1, 1);
    }

    for (int i = 1; i <= n; i++) {
        cin >> left_child[i] >> right_child[i];
    }

    dfs(1);

    cout << smallest_string[1] << endl;

    return 0;
}