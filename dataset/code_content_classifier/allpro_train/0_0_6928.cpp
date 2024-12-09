#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MOD 1000000007

using namespace std;

vector<int> cities_importance;

vector<vector<int>> adj_list;
vector<long long> subtree_sum;
vector<long long> factorials;

long long power_mod(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void calculate_subtree_sum(int node, int parent) {
    subtree_sum[node] = cities_importance[node];
    for (int child : adj_list[node]) {
        if (child != parent) {
            calculate_subtree_sum(child, node);
            subtree_sum[node] += subtree_sum[child];
        }
    }
}

int main() {
    int n;
    cin >> n;

    cities_importance.resize(n);
    adj_list.resize(n);
    subtree_sum.resize(n);
    factorials.resize(n+1);

    for (int i = 0; i < n; i++) {
        cin >> cities_importance[i];
    }

    for (int i = 1; i < n; i++) {
        int p_i;
        cin >> p_i;
        p_i--;
        adj_list[p_i].push_back(i);
        adj_list[i].push_back(p_i);
    }

    calculate_subtree_sum(0, -1);

    if (subtree_sum[0] % n != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long target_sum = subtree_sum[0] / n;
    map<long long, int> freq;

    for (int i = 0; i < n; i++) {
        freq[subtree_sum[i]]++;
    }

    for (pair<long long, int> p : freq) {
        if (p.first != target_sum && p.second > 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    factorials[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorials[i] = (factorials[i-1] * i) % MOD;
    }

    long long ans = 1;
    for (pair<long long, int> p : freq) {
        if (p.first != target_sum) {
            long long num_ways = factorials[p.second];
            ans = (ans * power_mod(num_ways, MOD-2)) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}