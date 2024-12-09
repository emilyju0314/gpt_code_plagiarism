#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

const vector<pair<int, int>> directions = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(const vector<string>& piece, vector<vector<bool>>& visited, int i, int j){
    if(i < 0 || j < 0 || i >= piece.size() || j >= piece[0].size() || visited[i][j] || piece[i][j] == '.'){
        return;
    }
    
    visited[i][j] = true;
    for(auto& dir : directions){
        dfs(piece, visited, i + dir.first, j + dir.second);
    }
}

bool canConstructCube(const vector<string>& piece){
    int n = piece.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    // Find the top-left unit cube of the core
    int start_i = -1, start_j = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(piece[i][j] == 'X'){
                start_i = i;
                start_j = j;
                break;
            }
        }
        if(start_i != -1) break;
    }
    
    dfs(piece, visited, start_i, start_j);
    
    return all_of(visited.begin(), visited.end(), [](const vector<bool>& row){
        return all_of(row.begin(), row.end(), [](bool cell){
            return cell;
        });
    });
}

int main() {
    int n;
    while(cin >> n && n != 0){
        vector<vector<string>> pieces(6, vector<string>(n));
        
        for(int i = 0; i < 6 * n; i++){
            char ch;
            cin >> ch;
            pieces[i / n][i % n] += ch;
        }
        
        vector<int> perm(6);
        iota(perm.begin(), perm.end(), 0);
        do{
            vector<string> constructed(n, string(n, '.'));
            for(int k = 0; k < 6; k++){
                for(int i = 0; i < n; i++){
                    constructed[k == 0 ? 0 : n - 1][i] += pieces[perm[k]][i];
                }
                for(int i = 0; i < n; i++){
                    constructed[i][k == 1 ? 0 : n - 1] += pieces[perm[k]][i].back();
                }
            }
            
            if(canConstructCube(constructed)){
                cout << "Yes" << endl;
                break;
            }
            
        } while(next_permutation(perm.begin(), perm.end()));
        
        if(!canConstructCube(constructed)){
            cout << "No" << endl;
        }
    }
    
    return 0;
}