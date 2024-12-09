#include <iostream>
#include <string>

using namespace std;

string createTree(string A, string B) {
    // Find the integer values at the roots
    int rootA = stoi(A.substr(A.find("[") + 1, A.find("]") - A.find("[") - 1));
    int rootB = stoi(B.substr(B.find("[") + 1, B.find("]") - B.find("[") - 1));
    int rootNew = rootA + rootB;
    
    // Extract the string representations of the left and right children of A and B
    string leftA = A.substr(1, A.find("]") - 1);
    string rightA = A.substr(A.find(")") + 1, A.length() - A.find(")") - 2);
    string leftB = B.substr(1, B.find("]") - 1);
    string rightB = B.substr(B.find(")") + 1, B.length() - B.find(")") - 2);

    // Recursively create the new rooted binary tree
    string newTree = "";
    if (leftA != "()" && leftB != "()") {
        newTree += "(" + createTree(leftA, leftB);
    } else if (leftA != "()") {
        newTree += leftA;
    } else if (leftB != "()") {
        newTree += leftB;
    }

    newTree += " [" + to_string(rootNew) + "] ";

    if (rightA != "()" && rightB != "()") {
        newTree += "(" + createTree(rightA, rightB) + ")";
    } else if (rightA != "()") {
        newTree += rightA;
    } else if (rightB != "()") {
        newTree += rightB;
    }

    return newTree;
}

int main() {
    string A, B;
    cin >> A >> B;

    string result = createTree(A, B);
    cout << result << endl;

    return 0;
}