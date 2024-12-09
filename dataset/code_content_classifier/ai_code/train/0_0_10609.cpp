#include <iostream>
#include <string>

using namespace std;

int countUncomfortablePairs(string tree) {
    int count = 0;
    
    for (int i = 0; i < tree.length(); i++) {
        if (tree[i] != '.') {
            int j = i + 2;
            while (tree[j] != '.' && j < tree.length()) {
                if (tree[i] == tree[j]) {
                    count++;
                }
                j++;
            }
        }
    }
    
    return count;
}

int main() {
    string tree;
    cin >> tree;
    
    int result = countUncomfortablePairs(tree);
    
    cout << result << endl;
    
    return 0;
}