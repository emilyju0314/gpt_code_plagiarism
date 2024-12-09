#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Post {
    int parent;
    string message;
    Post(int p, string m) {
        parent = p;
        message = m;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Post> posts;
    vector<int> depths(n, 0);

    for (int i = 0; i < n; i++) {
        int parent;
        string message;

        cin >> parent;
        cin.ignore(); // Ignore the newline character
        getline(cin, message);

        posts.push_back(Post(parent, message));
        if (parent != 0) {
            depths[i] = depths[parent - 1] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < depths[i]; j++) {
            cout << ".";
        }
        cout << posts[i].message << endl;
    }

    return 0;
}