#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> is_black;

void mark_black(int v) {
    is_black[v] = true;
    for (int child : adj_list[v]) {
        mark_black(child);
    }
}

void mark_white(int v) {
    is_black[v] = false;
}

string find_color(int v) {
    return is_black[v] ? "black" : "white";
}

int main() {
    int n, q;
    cin >> n >> q;
    
    adj_list.resize(n);
    is_black.resize(n, false);
    
    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        parent--;
        adj_list[parent].push_back(i);
    }
    
    while (q--) {
        int type, v;
        cin >> type >> v;
        v--;
        
        if (type == 1) {
            if (!is_black[v]) {
                mark_black(v);
            }
        } else if (type == 2) {
            mark_white(v);
        } else {
            cout << find_color(v) << endl;
        }
    }
    
    return 0;
}