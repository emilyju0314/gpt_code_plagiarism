#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Chain {
    int id;
    string sequence;
};

vector<Chain> chains;

void split(int idx, int pos) {
    string first_half = chains[idx].sequence.substr(0, pos + 1);
    string second_half = chains[idx].sequence.substr(pos + 1);
    
    Chain first = {chains.size(), first_half};
    Chain second = {chains.size() + 1, second_half};
    
    chains.push_back(first);
    chains.push_back(second);
    
    chains.erase(chains.begin() + idx);
}

void join(int idx1, int idx2) {
    chains[idx1].sequence += chains[idx2].sequence;
    chains.erase(chains.begin() + idx2);
}

bool isDetoxifiable(string chain) {
    int count_x = 0, count_o = 0;
    
    for(char c : chain) {
        if(c == 'x') {
            count_x++;
        } else {
            count_o++;
        }
        
        if(count_x > count_o) {
            return false;
        }
    }
    
    return chain.length() <= 2;
}

int main() {
    int total_paths;
    cin >> total_paths;
    
    for(int i = 0; i < total_paths; i++) {
        string pathogen;
        cin >> pathogen;
        
        chains.clear();
        Chain initial = {0, pathogen};
        chains.push_back(initial);
        
        int steps = 0;
        bool detoxifiable = true;
        
        while(detoxifiable) {
            detoxifiable = false;
            for(int j = 0; j < chains.size(); j++) {
                if(!isDetoxifiable(chains[j].sequence)) {
                    int pos;
                    for(int k = 0; k < chains[j].sequence.length() - 1; k++) {
                        if(chains[j].sequence[k] == 'x' && chains[j].sequence[k+1] == 'o') {
                            pos = k;
                            detoxifiable = true;
                            break;
                        }
                    }
                    
                    if(detoxifiable) {
                        split(j, pos);
                        cout << "split " << j << " " << pos << endl;
                        steps++;
                        break;
                    }
                }
            }
            
            if(!detoxifiable) {
                for(int j = 0; j < chains.size(); j++) {
                    if(chains[j].sequence.length() > 2) {
                        detoxifiable = true;
                        join(j, j + 1);
                        cout << "join " << j << " " << j + 1 << endl;
                        steps++;
                        break;
                    }
                }
            }
        }
        
        if(steps == 0) {
            cout << -1 << endl;
        } else {
            cout << steps << endl;
        }
    }
    
    return 0;
}