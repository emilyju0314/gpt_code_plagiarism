#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Artifact {
    string name;
    int number;
};

int main() {
    int k, n, m, q;
    cin >> k >> n >> m >> q;
    
    vector<string> basicArtifacts(n);
    for (int i = 0; i < n; i++) {
        cin >> basicArtifacts[i];
    }
    
    map<string, vector<Artifact>> compositeArtifacts;
    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        
        vector<Artifact> components;
        string component;
        while (cin >> component && component != ":") {
            int num;
            cin >> num;
            components.push_back({component, num});
        }
        
        compositeArtifacts[name] = components;
    }
    
    vector<map<string, int>> artifacts(k+1);
    
    for (int i = 0; i < q; i++) {
        int ai;
        string art;
        cin >> ai >> art;
        
        map<string, int>& inventory = artifacts[ai];
        inventory[art]++;
        
        for (auto [name, components] : compositeArtifacts) {
            bool canCraft = true;
            for (auto& component : components) {
                if (inventory[component.name] < component.number) {
                    canCraft = false;
                    break;
                }
            }
            if (canCraft) {
                for (auto& component : components) {
                    inventory[component.name] -= component.number;
                }
                inventory[name]++;
            }
        }
    }
    
    for (int i = 1; i <= k; i++) {
        cout << artifacts[i].size() << endl;
        vector<string> names;
        for (auto [name, num] : artifacts[i]) {
            names.push_back(name);
        }
        sort(names.begin(), names.end());
        for (auto name : names) {
            cout << name << " " << artifacts[i][name] << endl;
        }
    }
    
    return 0;
}