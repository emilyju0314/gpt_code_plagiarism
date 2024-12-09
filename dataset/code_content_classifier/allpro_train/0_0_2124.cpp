#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Vertex {
    int cv;
    char s;
    vector<Vertex*> children;
};

int countDistinctStrings(Vertex* vertex, unordered_set<string>& distinctStrings) {
    distinctStrings.insert(string(1, vertex->s)); // Current vertex's letter s
    int count = 1;
    
    for(Vertex* child : vertex->children) {
        count += countDistinctStrings(child, distinctStrings);
    }
    
    return count;
}

void buildTree(Vertex* root, vector<vector<int>>& edges, vector<int>& cvs, string& letters) {
    for(int i = 0; i < edges.size(); i++) {
        if(edges[i][0] == root->cv) {
            Vertex* child = new Vertex{cvs[i], letters[i], {}};
            root->children.push_back(child);
            buildTree(child, edges, cvs, letters);
        }
        else if(edges[i][1] == root->cv) {
            Vertex* child = new Vertex{cvs[i], letters[i], {}};
            root->children.push_back(child);
            buildTree(child, edges, cvs, letters);
        }
    }
}

void computeStatistics(Vertex* root, int& maxValue, int& countMaxValue) {
    unordered_set<string> distinctStrings;
    int currentMaxValue = countDistinctStrings(root, distinctStrings);
    
    if(currentMaxValue > maxValue) {
        maxValue = currentMaxValue;
        countMaxValue = 1;
    } else if(currentMaxValue == maxValue) {
        countMaxValue++;
    }
    
    for(Vertex* child : root->children) {
        computeStatistics(child, maxValue, countMaxValue);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> cvs(n);
    for(int i = 0; i < n; i++) {
        cin >> cvs[i];
    }
    
    string letters;
    cin >> letters;
    
    vector<vector<int>> edges(n-1, vector<int>(2));
    for(int i = 0; i < n-1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    Vertex* root = new Vertex{cvs[0], letters[0], {}};
    buildTree(root, edges, cvs, letters);
    
    int maxValue = 0;
    int countMaxValue = 0;
    computeStatistics(root, maxValue, countMaxValue);
    
    cout << maxValue << endl;
    cout << countMaxValue << endl;
    
    return 0;
}