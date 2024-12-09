#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> memory_clusters(n);
    vector<int> arrays(m);
    
    for(int i = 0; i < n; i++) {
        cin >> memory_clusters[i];
    }
    
    for(int i = 0; i < m; i++) {
        cin >> arrays[i];
    }
    
    sort(memory_clusters.begin(), memory_clusters.end(), greater<int>());
    sort(arrays.begin(), arrays.end(), greater<int>());
    
    int count = 0;
    int j = 0;
    for(int i = 0; i < n && j < m; i++) {
        if(memory_clusters[i] >= arrays[j]) {
            count++;
            j++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}