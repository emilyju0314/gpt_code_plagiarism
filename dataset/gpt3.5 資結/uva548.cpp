#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<int> values;

int findRootIndex(int start, int end) {
    int root = postorder.back();
    return distance(inorder.begin() + start, find(inorder.begin() + start, inorder.begin() + end, root));
}

void buildTree(int inStart, int inEnd, int postStart, int postEnd) {
    if (postStart >= postEnd) {
        return;
    }

    int rootIndex = findRootIndex(inStart, inEnd);
    values.push_back(inorder[rootIndex]);
    buildTree(inStart, rootIndex, postStart, postStart + rootIndex - inStart);
    buildTree(rootIndex + 1, inEnd, postStart + rootIndex - inStart, postEnd - 1);
}

int getMinPath(int node, int sum) {
    if (values[node] == sum && node >= values.size() / 2) {
        return sum;
    }

    if (values[node] < sum) {
        return min(getMinPath(node * 2, sum - values[node]), getMinPath(node * 2 + 1, sum - values[node]));
    }

    return sum;
}

int main() {
    int num;
    while (cin >> num) {
        inorder.clear();
        postorder.clear();
        values.clear();

        for (int i = 0; i < num; i++) {
            int value;
            cin >> value;
            inorder.push_back(value);
        }

        for (int i = 0; i < num; i++) {
            int value;
            cin >> value;
            postorder.push_back(value);
        }

        buildTree(0, num, 0, num);

        int minSum = 9999999;
        for (int i = 0; i < values.size() / 2; i++) {
            int sum = getMinPath(i, values[i]);
            if (sum < minSum) {
                minSum = sum;
            }
        }

        cout << minSum << endl;
    }

    return 0;
}