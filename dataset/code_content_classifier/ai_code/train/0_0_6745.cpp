#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

const int inf = 1e9;

struct Base {
    string country;
    int idx;
};

struct Edge {
    string from;
    int from_idx;
    string to;
    int to_idx;
    int cost;
};

int main() {
    int n;
    cin >> n;

    vector<string> country_names(n);
    vector<int> num_bases(n);
    vector<vector<Base>> bases(n);
    map<string, int> base_id;

    for (int i = 0; i < n; ++i) {
        cin >> country_names[i] >> num_bases[i];
        bases[i].resize(num_bases[i]);
        for (int j = 0; j < num_bases[i]; ++j) {
            bases[i][j].country = country_names[i];
            bases[i][j].idx = j;
            base_id[country_names[i] + to_string(j)] = bases[i].size();
        }
    }

    int e;
    cin >> e;

    vector<Edge> edges;
    for (int i = 0; i < e; ++i) {
        string from_country, to_country;
        int from_base, to_base, cost;
        cin >> from_country >> from_base >> to_country >> to_base >> cost;

        edges.push_back({from_country, from_base, to_country, to_base, cost});
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        string start_country;
        int start_base;
        cin >> start_country >> start_base;

        vector<vector<int>> dist(n, vector<int>(num_bases[n], inf));
        vector<vector<pair<int, int>>> path(n, vector<pair<int, int>>(num_bases[n], {-1, -1}));

        dist[start_country][start_base] = 0;
        priority_queue<pair<int, Base>, vector<pair<int, Base>>, greater<pair<int, Base>>> pq;
        pq.push({0, {start_country, start_base}});

        while (!pq.empty()) {
            auto [cost, base] = pq.top();
            pq.pop();

            int d = dist[base.country][base.idx];
            if (cost > d) continue;

            for (auto& edge : edges) {
                if (edge.from == base.country && edge.from_idx == base.idx) {
                    int new_cost = d + edge.cost;
                    if (new_cost < dist[edge.to][edge.to_idx]) {
                        dist[edge.to][edge.to_idx] = new_cost;
                        path[edge.to][edge.to_idx] = {base.idx, base_id[edge.to + to_string(edge.to_idx)}};
                        pq.push({new_cost, {edge.to, edge.to_idx}});
                    }
                }
            }
        }

        int min_cost = inf;
        vector<pair<int, int>> min_path;
        for (int j = 0; j < n; ++j) {
            if (j == start_country) continue;
            for (int k = 0; k < num_bases[j]; ++k) {
                if (dist[j][k] < min_cost) {
                    min_cost = dist[j][k];
                    min_path.clear();
                    int cur_base = k;
                    string cur_country = country_names[j];
                    
                    while (cur_base != -1) {
                        min_path.push_back({base[country_names[j] + to_string(cur_base)], cur_base});
                        cur_base = path[country_names[j]][cur_base].first;
                        cur_country = country_names[path[country_names[j]][cur_base].second];
                    }
                    reverse(min_path.begin(), min_path.end());
                }
            }
        }

        if (min_cost == inf) {
            cout << "Impossible" << endl;
        } else {
            cout << min_cost << endl;
            for (auto& [base, idx] : min_path) {
                cout << country_names[base.country] << " " << base << " " << country_names[idx] << " " << idx << endl;
            }
        }
        cout << "-----" << endl;
    }

    return 0;
}