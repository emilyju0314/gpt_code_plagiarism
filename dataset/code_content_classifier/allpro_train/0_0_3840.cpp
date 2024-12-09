#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<map<int, char>> tree1, tree2;
    tree1.push_back({});
    tree2.push_back({});
    
    vector<pair<int, int>> backward_path;
    backward_path.push_back({1, 1});
    
    map<string, int> good_combinations;
    good_combinations["1 1"] = 1;
    
    for(int i = 0; i < n; i++) {
        int t, v;
        char c;
        cin >> t >> v >> c;
        
        if(t == 1) {
            tree1.push_back({});
            tree1[v][tree1[v].size() + 1] = c;
            
            backward_path.push_back({1, tree1.size()-1});
            string path_str = to_string(backward_path.size()) + " " + to_string(tree1.size()-1);
            
            for(int j = 1; j < backward_path.size(); j++) {
                string new_path = path_str + " " + to_string(backward_path[j].first) + " " + to_string(backward_path[j].second);
                good_combinations[new_path] += 1;
            }
        } else {
            tree2.push_back({});
            tree2[v][tree2[v].size() + 1] = c;
            
            for(int j = backward_path.size()-1; j >= 0; j--) {
                int curr_v = backward_path[j].second;
                if(tree2[v].count(curr_v) > 0) {
                    if(j == 0) backward_path.push_back({1, v});
                    else backward_path.push_back({backward_path[j].first, v});
                    
                    string path_str = to_string(backward_path[j].first) + " " + to_string(v);
                    string new_path = path_str + " " + to_string(backward_path.size()-1) + " " + to_string(curr_v);
                    good_combinations[new_path] += 1;
                }
            }
        }
        
        int total_good_combinations = 0;
        for(auto it : good_combinations) {
            total_good_combinations += it.second;
        }
        cout << total_good_combinations << endl;
    }
    
    return 0;
}