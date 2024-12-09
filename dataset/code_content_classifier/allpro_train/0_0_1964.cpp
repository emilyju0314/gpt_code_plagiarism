#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, pair<long long, long long>> parent;
unordered_map<long long, long long> weight;
unordered_map<long long, vector<long long>> children;
unordered_map<long long, long long> subtree_sum;

long long last = 0;

void add_node(long long r, long long w) {
    long long next_index = parent.size() + 1;
    parent[next_index] = {r, w};
    weight[next_index] = w;
    children[r].push_back(next_index);
    subtree_sum[next_index] = w + subtree_sum[r];

    last = 0;
}

long long max_sequence(long long r, long long x) {
    long long max_sum = 0;
    while(r != 1) {
        long long curr_weight = weight[r];
        long long sum = 0;
        long long max_weight = curr_weight;
        long long curr = r;

        while(curr != 1 && sum + curr_weight <= x) {
            sum += curr_weight;
            if(curr_weight > max_weight) {
                max_weight = curr_weight;
            }
            curr = parent[curr].first;
            curr_weight = weight[curr];
        }

        if(curr == 1 && sum + curr_weight <= x) {
            sum += curr_weight;
            if(curr_weight > max_weight) {
                max_weight = curr_weight;
            }
        }

        r = parent[r].first;
        max_sum = max(max_sum, sum);

        if(max_weight >= weight[r]) {
            break;
        }
    }

    last = max_sum;
    return max_sum;
}

int main() {
    long long Q;
    cin >> Q;

    for(long long i = 0; i < Q; i++) {
        long long type, p, q;
        cin >> type >> p >> q;

        if(type == 1) {
            add_node(p, q);
        } else {
            cout << max_sequence(p, q) << endl;
        }
    }

    return 0;
}