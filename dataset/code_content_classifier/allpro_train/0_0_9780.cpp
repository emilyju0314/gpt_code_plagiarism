#include <bits/stdc++.h>
using namespace std;

string transformTree(string tree) {
    if(tree.length() == 1) {
        return tree;
    }

    int idx = 1, balance = 0;
    pair<string,string> left, right;
    while(idx < tree.length()) {
        if(balance == 1 && tree[idx] == ' ') {
            left.first = tree.substr(1, idx-1);
            left.second = tree.substr(idx+1);
        }
        if(tree[idx] == '(') {
            balance++;
        } else if(tree[idx] == ')') {
            balance--;
        }
        idx++;
    }
    right.first = tree.substr(1, idx-2);
    right.second = tree.substr(idx+1, tree.length()-idx-2);

    left.first = transformTree(left.first);
    left.second = transformTree(left.second);
    right.first = transformTree(right.first);
    right.second = transformTree(right.second);
    
    int i = 0;
    while((i < left.first.length()) && (i < right.first.length()) && (left.first[i] == right.first[i])) {
        i++;
    }
    if((i < left.first.length()) && (i < right.first.length()) && (left.first[i] > right.first[i])) {
        swap(left, right);
    }

    return "(" + left.first + " " + left.second + ")" + right.first + " " + right.second + ")";
}

int main() {
    string tree;
    while(cin >> tree) {
        if(tree == "0") break;
        cout << transformTree(tree) << endl;
    }
    return 0;
}