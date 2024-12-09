#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int rock_count = 0, paper_count = 0, scissor_count = 0;
        for(char c : s) {
            if(c == 'R') {
                rock_count++;
            } else if(c == 'P') {
                paper_count++;
            } else {
                scissor_count++;
            }
        }

        char choice;
        if(paper_count >= rock_count && paper_count >= scissor_count) {
            choice = 'S';
        } else if(rock_count >= paper_count && rock_count >= scissor_count) {
            choice = 'P';
        } else {
            choice = 'R';
        }

        for(int i = 0; i < s.size(); i++) {
            cout << choice;
        }

        cout << endl;
    }

    return 0;
}