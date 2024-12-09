#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const int MAX_CHAR = 26;

struct TrieNode {
    TrieNode* children[MAX_CHAR];
    int relevance;

    TrieNode() {
        relevance = 0;
        for (int i = 0; i < MAX_CHAR; i++) {
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, const string& pseudonym) {
    TrieNode* current = root;
    for (char c : pseudonym) {
        int index = c - 'a';
        if (current->children[index] == nullptr) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
        current->relevance++;
    }
}

pair<int, int> findBestMatch(TrieNode* root, const string& student) {
    int max_relevance = 0;
    int best_match = -1;
    TrieNode* current = root;
    for (char c : student) {
        int index = c - 'a';
        if (current->children[index] == nullptr) {
            break;
        }
        current = current->children[index];
        max_relevance++;
        if (current->relevance > max_relevance) {
            max_relevance = current->relevance;
            best_match = max_relevance;
        }
    }
    return {max_relevance, best_match};
}

int main() {
    int n;
    cin >> n;

    TrieNode* root = new TrieNode();
    vector<string> students(n);
    vector<string> pseudonyms(n);
    unordered_map<string, int> student_index;

    for (int i = 0; i < n; i++) {
        cin >> students[i];
        student_index[students[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> pseudonyms[i];
        insert(root, pseudonyms[i]);
    }

    int total_quality = 0;
    vector<int> matching(n);

    for (const string& student : students) {
        auto [relevance, best_match] = findBestMatch(root, student);
        total_quality += relevance;
        matching[student_index[student]] = best_match;
    }

    cout << total_quality << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " " << matching[i] << endl;
    }

    return 0;
}