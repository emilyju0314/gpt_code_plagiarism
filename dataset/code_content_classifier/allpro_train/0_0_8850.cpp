#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<string>> pages(n, vector<string>(k));
    for(int i=0; i<n; i++) {
        int p;
        cin >> p;
        
        for(int j=0; j<k; j++) {
            cin >> pages[i][j];
        }
    }

    vector<int> in_degree(26, 0);
    vector<vector<int>> adj_list(26, vector<int>());

    // Build the adjacency list and calculate in-degrees
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<k; j++) {
            string word1 = pages[i][j];
            string word2 = pages[i+1][j];
            
            for(int l=0; l<min(word1.length(), word2.length()); l++) {
                if(word1[l] != word2[l]) {
                    int u = word1[l] - 'a';
                    int v = word2[l] - 'a';
                    
                    in_degree[v]++;
                    adj_list[u].push_back(v);
                    
                    break; // Break the loop to prevent additional edges being added
                }
            }
        }
    }

    // Topological sort to reconstruct the alphabet
    string result = "";
    vector<int> order;
    for(int i=0; i<26; i++) {
        if(in_degree[i] == 0) {
            order.push_back(i);
        }
    }

    for(int i=0; i<order.size(); i++) {
        result += ('a' + order[i]);
        
        for(int j=0; j<adj_list[order[i]].size(); j++) {
            int v = adj_list[order[i]][j];
            in_degree[v]--;
            
            if(in_degree[v] == 0) {
                order.push_back(v);
            }
        }
    }

    if(result.length() != 26) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}