#include <iostream>
#include <vector>

using namespace std;

bool canReached(vector<int>& permutation, vector<int>& favourites) {
    int n = permutation.size();
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        
        visited[i] = true;
        int current = permutation[i];
        while (favourites[current-1] != i+1) {
            if (visited[favourites[current-1]-1]) return false;
            
            visited[favourites[current-1]-1] = true;
            current = permutation[favourites[current-1]-1];
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> permutation(n);
    vector<int> favourites(n);
    
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> favourites[i];
    }
    
    if (canReached(permutation, favourites)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}